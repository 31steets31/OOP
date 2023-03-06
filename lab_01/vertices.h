#ifndef __VERTICES_FUNCTIONS_AND_TYPES__
#define __VERTICES_FUNCTIONS_AND_TYPES__

#include "points.h"
#include "model_actions.h"
#include "errors.h"

struct point_t;

/**
 * \brief Vertexes struct
 */
struct vertices_t
{
    point_t* points;
    int n_vertices;
};

/**
 * \brief Initialize vertices
 *
 * \return
 */
void InitVertices(vertices_t& vertices);
/**
 * \brief Allocate vertices
 *
 * \param vertices
 * \param count
 */
errors AllocateVertices(vertices_t& vertices, int& count);
/**
 * \brief Transfer vertices
 *
 * \param vertices
 * \param t_coord
 */
void TransferVertices(vertices_t& vertices, const transfer_t& t_coord);
/**
 * \brief Rotate vertices
 *
 * \param vertices
 * \param r_angles
 */
void RotateVertices(vertices_t& vertices, const rotate_t& r_angles);
/**
 * \brief Scale vertices
 *
 * \param vertices
 * \param s_coeff
 */
void ScaleVertices(vertices_t& vertices, const scale_t& s_coeff);
/**
 * \brief Free verticles
 *
 * \param vertices
 */
void FreeVertices(vertices_t& vertices);

#endif // __VERTICES_FUNCTIONS_AND_TYPES__
