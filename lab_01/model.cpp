#include <iostream>

#include "model.h"
#include "errors.h"
#include "paint.h"
#include "defines.h"
#include "process.h"

/**
 * \brief Initialize vertices
 *
 * \return
 */
void InitVertices(vertexes_t& vertices)
{
	vertices.n_vertices = 0;
	vertices.points = NULL;
}

/**
 * \brief Allocate vertices
 * 
 * \param vertices
 * \param count
 */
void AllocateVertices(vertexes_t& vertices, int& count)
{
	vertices.n_vertices = count;
	vertices.points = (vertex_t *) malloc(sizeof(vertex_t) * count);
}

/**
 * \brief Initialize faces
 *
 * \return
 */
void InitFaces(faces_t& faces)
{
	faces.n_faces = 0;
	faces.arr = NULL;
}

/**
 * \brief Allocate faces
 * 
 * \param faces
 * \param count
 */
void AllocateFaces(faces_t& faces, int& count)
{
	faces.n_faces = count;
	faces.arr = (face_t *) malloc(sizeof(face_t) * count);
}

/**
 * \brief Initialize model
 *
 * \return
 */
model_t& InitModel(void)
{
	static model_t model;

	// Initialize vertices
	InitVertices(model.vertices);

	// Initialize vertices
	InitFaces(model.faces);

	return model;
}

/**
 * \brief Draw model
 *
 * \param model
 * \param canvas
 * \return
 */
errors DrawModel(const model_t &model, canvas_t &canvas)
{
	// Clear canvas
	ClearCanvas(canvas);

	// Draw model
	AddLines(canvas, model.vertices, model.faces);

	return ERR_SUCCESS;
}

/**
 * \brief Transfer point
 * 
 * \param point
 * \param t_coord
 */
void TransferPoint(vertex_t &point, const transfer_t& t_coord)
{
	point.x += t_coord.dx;
	point.y += t_coord.dy;
	point.z += t_coord.dz;
}

/**
 * \brief Transfer vertices
 * 
 * \param vertices
 * \param t_coord
 */
void TransferVertices(vertexes_t &vertices, const transfer_t& t_coord)
{
	for (int i = 0; i < vertices.n_vertices; ++i)
		TransferPoint(vertices.points[i], t_coord);
}

/**
 * \brief Transfer model
 * 
 * \param model
 * \param t_coord
 * \return 
 */
errors TransferModel(model_t& model, const transfer_t& t_coord)
{
	// Transfer vertices
	TransferVertices(model.vertices, t_coord);

	return ERR_SUCCESS;
}

/**
 * \brief Rotate point around Oy and Oz
 * 
 * \param point
 * \param r_angles
 */
void RotatePointYZ(vertex_t& point, const rotate_t& r_angles)
{
	point.y = r_angles.y_center + 
		(point.y - r_angles.y_center) *
		cos(r_angles.x_angle * M_PI / 180.0) - 
		(point.z - r_angles.z_center) *
		sin(r_angles.x_angle * M_PI / 180.0);

	point.z = r_angles.z_center + 
		(point.y - r_angles.y_center) *
		sin(r_angles.x_angle * M_PI / 180.0) + 
		(point.z - r_angles.z_center) *
		cos(r_angles.x_angle * M_PI / 180.0);
}

/**
 * \brief Rotate point around Ox and Oz
 *
 * \param point
 * \param r_angles
 */
void RotatePointXZ(vertex_t& point, const rotate_t& r_angles)
{
	point.x = r_angles.x_center + (point.x - r_angles.x_center) *
		cos(r_angles.y_angle * M_PI / 180.0) + 
		(point.z - r_angles.z_center) *
		sin(r_angles.y_angle * M_PI / 180.0);

	point.z = r_angles.z_center - (point.x - r_angles.x_center) *
		sin(r_angles.y_angle * M_PI / 180.0) + 
		(point.z - r_angles.z_center) *
		cos(r_angles.y_angle * M_PI / 180.0);
}

/**
 * \brief Rotate point around Ox and Oy
 * 
 * \param point
 * \param r_angles
 */
void RotatePointXY(vertex_t& point, const rotate_t& r_angles)
{
	point.x = r_angles.x_center + (point.x - r_angles.x_center) *
		cos(r_angles.z_angle * M_PI / 180.0) - 
		(point.y - r_angles.y_center) *
		sin(r_angles.z_angle * M_PI / 180.0);

	point.y = r_angles.y_center + (point.x - r_angles.x_center) *
		sin(r_angles.z_angle * M_PI / 180.0) + 
		(point.y - r_angles.y_center) *
		cos(r_angles.z_angle * M_PI / 180.0);
}

/**
 * \brief Rotate vertices
 * 
 * \param vertices
 * \param r_angles
 */
void RotateVertices(vertexes_t &vertices, const rotate_t& r_angles)
{
	for (int i = 0; i < vertices.n_vertices; ++i)
	{
		// Get vertex
		vertex_t vertex = vertices.points[i];

		// Rotate around center point r_angles.x_center, r_angles.y_center, r_angles.z_center
		RotatePointYZ(vertex, r_angles);

		vertex = vertices.points[i];

		RotatePointXZ(vertex, r_angles);

		vertex = vertices.points[i];

		RotatePointXY(vertex, r_angles);
	}
}

/**
 * \brief Rotate model
 * 
 * \param model
 * \param r_angles
 * \return 
 */
errors RotateModel(model_t& model, const rotate_t& r_angles)
{
	// Rotate vertices
	RotateVertices(model.vertices, r_angles);

	return ERR_SUCCESS;
}

/**
 * \brief Scale point
 * 
 * \param point
 * \param s_coeff
 */
void ScalePoint(vertex_t &point, const scale_t& s_coeff)
{
	point.x = s_coeff.x_center + (point.x - s_coeff.x_center) * s_coeff.kx;
	point.y = s_coeff.y_center + (point.y - s_coeff.y_center) * s_coeff.ky;
	point.z = s_coeff.z_center + (point.z - s_coeff.z_center) * s_coeff.kz;
}

/**
 * \brief Scale vertices
 * 
 * \param vertices
 * \param s_coeff
 */
void ScaleVertices(vertexes_t &vertices, const scale_t& s_coeff)
{
	for (int i = 0; i < vertices.n_vertices; ++i)
		// Scale coordinates around center point s_coeff.x_center, s_coeff.y_center, s_coeff.z_center
		ScalePoint(vertices.points[i], s_coeff);
}

/**
 * \brief Scale model
 * 
 * \param model
 * \param s_coeff
 * \return 
 */
errors ScaleModel(model_t& model, const scale_t& s_coeff)
{
	// Scale vertices
	ScaleVertices();

	return ERR_SUCCESS;
}

/**
 * \brief Free verticles
 * 
 * \param vertices
 */
void FreeVertices(vertexes_t &vertices)
{
	free(vertices.points);
}

/**
 * \brief Free faces
 * 
 * \param faces
 */
void FreeFaces(faces_t& faces)
{
	free(faces.arr);
}

/**
 * \brief Free model
 *
 * \param model
 * \return
 */
void FreeModel(model_t &model)
{
	// Free vertices
	FreeVertices(model.vertices);

	// Free faces
	FreeFaces(model.faces);
}