#ifndef __PAINT__
#define __PAINT__

#include "points.h"
#include "vertices.h"
#include "faces.h"
#include "canvas.h"

/**
 * \brief Draw line on canvas
 *
 * \param canvas
 * \param a
 * \param b
 */
void AddLine(const canvas_t& canvas, const point_t& a, const point_t& b);
/**
 * \brief Draw lines on canvas
 *
 * \param canvas
 * \param vertexes
 * \param faces
 */
void AddLines(const canvas_t& canvas, vertices_t& vertexes, faces_t& faces);

#endif // __PAINT__