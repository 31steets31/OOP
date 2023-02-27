#include <iostream>

#include "vertices.h"

/**
 * \brief Initialize vertices
 *
 * \return
 */
void InitVertices(vertices_t& vertices)
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
void AllocateVertices(vertices_t& vertices, int& count)
{
	vertices.n_vertices = count;
	vertices.points = (point_t*)malloc(sizeof(point_t) * count);
}

/**
 * \brief Transfer vertices
 *
 * \param vertices
 * \param t_coord
 */
void TransferVertices(vertices_t& vertices, const transfer_t& t_coord)
{
	for (int i = 0; i < vertices.n_vertices; ++i)
		TransferPoint(vertices.points[i], t_coord);
}

/**
 * \brief Rotate vertices
 *
 * \param vertices
 * \param r_angles
 */
void RotateVertices(vertices_t& vertices, const rotate_t& r_angles)
{
	for (int i = 0; i < vertices.n_vertices; ++i)
	{
		// Rotate around center point r_angles.x_center, r_angles.y_center, r_angles.z_center
		RotatePointYZ(vertices.points[i], r_angles);

		RotatePointXZ(vertices.points[i], r_angles);

		RotatePointXY(vertices.points[i], r_angles);
	}
}

/**
 * \brief Scale vertices
 *
 * \param vertices
 * \param s_coeff
 */
void ScaleVertices(vertices_t& vertices, const scale_t& s_coeff)
{
	for (int i = 0; i < vertices.n_vertices; ++i)
		// Scale coordinates around center point s_coeff.x_center, s_coeff.y_center, s_coeff.z_center
		ScalePoint(vertices.points[i], s_coeff);
}

/**
 * \brief Free verticles
 *
 * \param vertices
 */
void FreeVertices(vertices_t& vertices)
{
	free(vertices.points);
}