#include <iostream>

#include "model.h"

/**
 * \brief Initialize model
 *
 * \param filename
 * \return
 */
model_t &InitModel(void)
{
	static model_t model;

	model.n_vertices = 0;
	model.n_faces = 0;
	model.vertices = NULL;
	model.faces = NULL;

	return model;
}

/**
 * \brief Free model
 *
 * \param filename
 * \return
 */
void FreeModel(model_t &model)
{
	// Free vertices
	free(model.vertices);

	// Free faces
	free(model.faces);
}