#include <iostream>

#include "vertices.h"
#include "errors.h"

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
errors AllocateVertices(vertices_t& vertices, int& count)
{
	// Return code
	errors rc = ERR_SUCCESS;

	vertices.points = (point_t*)malloc(sizeof(point_t) * count);

	if (!vertices.points)
		rc = ERR_ALLOCATE;
	else
		vertices.n_vertices = count;

	return rc;
}

/**
 * \brief Transfer vertices
 *
 * \param vertices
 * \param t_coord
 */
void TransferVertices(vertices_t& vertices, const transfer_t& t_coord)
{
	TransferPoints(vertices.points, vertices.n_vertices, t_coord);
}

/**
 * \brief Rotate vertices
 *
 * \param vertices
 * \param r_angles
 */
void RotateVertices(vertices_t& vertices, const rotate_t& r_angles)
{
	RotatePoints(vertices.points, vertices.n_vertices, r_angles);
}

/**
 * \brief Scale vertices
 *
 * \param vertices
 * \param s_coeff
 */
void ScaleVertices(vertices_t& vertices, const scale_t& s_coeff)
{
	ScalePoints(vertices.points, vertices.n_vertices, s_coeff);
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