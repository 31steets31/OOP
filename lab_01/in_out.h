#ifndef __IN_OUT__
#define __IN_OUT__

#include "model.h"
#include "errors.h"

/**
 * \brief Load model from file
 *
 * \param filename
 * \return
 */
errors LoadModel(model_t& model, const char *filename);
/**
 * \brief Print error message
 *
 * \param err
 */
void PrintErrorMessage(const errors& err);

#endif // __IN_OUT__
