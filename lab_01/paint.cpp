#include "paint.h"
#include "points.h"
#include "canvas.h"

/**
 * \brief Draw line on canvas
 * 
 * \param canvas
 * \param a
 * \param b
 */
void AddLine(const canvas_t& canvas, const project_point_t& a, const project_point_t& b)
{
	canvas.canvas->addLine(
		a.x, a.y,
		b.x, b.y
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
		face_t face = GetFaceByIndex(faces.arr, i);

		// Get vertexes
		point_t a = GetPointByIndex(vertexes.points, face.a);
		point_t b = GetPointByIndex(vertexes.points, face.b);

		// Project point
		project_point_t project_a;
		project_point_t project_b;

		ProjectPoint(project_a, a);
		ProjectPoint(project_b, b);

		// Draw line on canvas
		AddLine(canvas, project_a, project_b);
	}
}
