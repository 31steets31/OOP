#ifndef __PAINT__
#define __PAINT__

#include <QGraphicsScene>

#include "model.h"
#include "point.h"
#include "vertices.h"
#include "faces.h"

/**
 * \brief Canvas
 */
struct canvas_t
{
	QGraphicsScene* canvas;
};

/**
 * \brief Clear canvas
 *
 * \param canvas
 * \return
 */
void ClearCanvas(canvas_t& canvas);
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