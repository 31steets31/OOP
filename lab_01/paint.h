#ifndef __PAINT__
#define __PAINT__

#include <QGraphicsScene>

#include "model.h"

/**
 * \brief Canvas
 */
struct canvas_t
{
	QGraphicsScene *canvas;
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
void AddLine(const canvas_t& canvas, const vertex_t& a, const vertex_t& b);
/**
 * \brief Draw lines on canvas
 *
 * \param canvas
 * \param a
 * \param b
 */
void AddLines(const canvas_t& canvas, vertexes_t& vertexes, faces_t& faces);

#endif // __PAINT__