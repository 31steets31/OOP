#include <iostream>

#include "model.h"
#include "errors.h"
#include "paint.h"
#include "defines.h"
#include "process.h"

/**
 * \brief Initialize model
 *
 * \return
 */
model_t& InitModel(void)
{
	static model_t model;

	model.n_vertices = 0;
	model.n_faces = 0;
	model.vertices = NULL;
	model.faces = NULL;

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
	for (int i = 0; i < model.n_faces; ++i)
	{
		// Get face
		face_t face = model.faces[i];

		// Draw line
		canvas.canvas->addLine(
			model.vertices[face.a].x + CANVAS_WIDTH / 2,
			-model.vertices[face.a].y + CANVAS_HEIGHT / 2,
			model.vertices[face.b].x + CANVAS_WIDTH / 2,
			-model.vertices[face.b].y + CANVAS_HEIGHT / 2
		);
	}

	return ERR_SUCCESS;
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
	for (int i = 0; i < model.n_vertices; ++i)
	{
		model.vertices[i].x += t_coord.dx;
		model.vertices[i].y += t_coord.dy;
		model.vertices[i].z += t_coord.dz;
	}

	return ERR_SUCCESS;
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
	for (int i = 0; i < model.n_vertices; ++i)
	{
		// Get vertex
		vertex_t vertex = model.vertices[i];

		// Rotate around center point r_angles.x_center, r_angles.y_center, r_angles.z_center
		model.vertices[i].y = r_angles.y_center + (vertex.y - r_angles.y_center) *
			cos(r_angles.x_angle * M_PI / 180.0) - (vertex.z - r_angles.z_center) *
			sin(r_angles.x_angle * M_PI / 180.0);
		model.vertices[i].z = r_angles.z_center + (vertex.y - r_angles.y_center) *
			sin(r_angles.x_angle * M_PI / 180.0) + (vertex.z - r_angles.z_center) *
			cos(r_angles.x_angle * M_PI / 180.0);

		vertex = model.vertices[i];

		model.vertices[i].x = r_angles.x_center + (vertex.x - r_angles.x_center) *
			cos(r_angles.y_angle * M_PI / 180.0) + (vertex.z - r_angles.z_center) *
			sin(r_angles.y_angle * M_PI / 180.0);
		model.vertices[i].z = r_angles.z_center - (vertex.x - r_angles.x_center) *
			sin(r_angles.y_angle * M_PI / 180.0) + (vertex.z - r_angles.z_center) *
			cos(r_angles.y_angle * M_PI / 180.0);

		vertex = model.vertices[i];

		model.vertices[i].x = r_angles.x_center + (vertex.x - r_angles.x_center) *
			cos(r_angles.z_angle * M_PI / 180.0) - (vertex.y - r_angles.y_center) *
			sin(r_angles.z_angle * M_PI / 180.0);
		model.vertices[i].y = r_angles.y_center + (vertex.x - r_angles.x_center) *
			sin(r_angles.z_angle * M_PI / 180.0) + (vertex.y - r_angles.y_center) *
			cos(r_angles.z_angle * M_PI / 180.0);
	}

	return ERR_SUCCESS;
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
	for (int i = 0; i < model.n_vertices; ++i)
	{
		// Scale coordinates around center point s_coeff.x_center, s_coeff.y_center, s_coeff.z_center
		model.vertices[i].x = s_coeff.x_center + (model.vertices[i].x - s_coeff.x_center) * s_coeff.kx;
		model.vertices[i].y = s_coeff.y_center + (model.vertices[i].y - s_coeff.y_center) * s_coeff.ky;
		model.vertices[i].z = s_coeff.z_center + (model.vertices[i].z - s_coeff.z_center) * s_coeff.kz;
	}

	return ERR_SUCCESS;
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
	free(model.vertices);

	// Free faces
	free(model.faces);
}