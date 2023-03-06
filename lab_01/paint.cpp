#include "paint.h"
#include "defines.h"
#include "points.h"
#include "faces.h"

/**
 * \brief Draw line on canvas
 * 
 * \param canvas
 * \param a
 * \param b
 */
void AddLine(const canvas_t& canvas, const point_t& a, const point_t& b)
{
	canvas.canvas->addLine(
		a.x, -a.y,
		b.x, -b.y
	);
}

/**
 * \brief Draw lines on canvas
 * 
 * \param canvas
 * \param vertexes
 * \param faces
 */
void AddLines(const canvas_t &canvas, vertices_t &vertexes, faces_t &faces)
{
	for (int i = 0; i < faces.n_faces; ++i)
	{
		// Get face
		face_t& face = GetFaceByIndex(faces.arr, i);

		// Get vertexes
		point_t& a = GetPointByIndex(vertexes.points, face.a);
		point_t& b = GetPointByIndex(vertexes.points, face.b);

		// Project point
		ProjectPoint(a);
		ProjectPoint(b);

		// Draw line on canvas
		AddLine(canvas, a, b);
	}
}
