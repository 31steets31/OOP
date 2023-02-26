#include <iostream>

#include "model.h"

/**
 * \brief Free model
 *
 * \param filename
 * \return
 **/
void FreeModel(model_t * model)
{
	// Free vertices
	free(model->vertices);

	// Free faces
	free(model->faces);

	// Free model
	free(model);
}