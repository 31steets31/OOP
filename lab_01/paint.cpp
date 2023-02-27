#include "paint.h"
#include "model.h"
#include "defines.h"

/**
 * \brief Clear canvas
 *
 * \param canvas
 * \return
 */
void ClearCanvas(canvas_t& canvas)
{
	canvas.canvas->clear();
}

/**
 * \brief Draw line on canvas
 * 
 * \param canvas
 * \param a
 * \param b
 */
void AddLine(const canvas_t& canvas, const vertex_t& a, const vertex_t& b)
{
	canvas.canvas->addLine(
		a.x + CANVAS_WIDTH / 2, -a.y + CANVAS_HEIGHT / 2,
		b.x + CANVAS_WIDTH / 2, -b.y + CANVAS_HEIGHT / 2
	);
}

/**
 * \brief Draw lines on canvas
 * 
 * \param canvas
 * \param a
 * \param b
 */
void AddLines(const canvas_t &canvas, vertexes_t &vertexes, faces_t &faces)
{
	for (int i = 0; i < faces.n_faces; ++i)
	{
		// Get face
		face_t face = faces.arr[i];

		// Get vertexes
		vertex_t& a = vertexes.points[face.a];
		vertex_t& b = vertexes.points[face.b];

		// Draw line on canvas
		AddLine(canvas, a, b);
	}
}
