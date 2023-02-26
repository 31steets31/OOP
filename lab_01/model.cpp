#include <iostream>

#include "model.h"
#include "errors.h"
#include "paint.h"
#include "defines.h"

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