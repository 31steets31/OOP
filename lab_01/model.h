#ifndef __MODEL_FUNCTIONS_AND_TYPES__
#define __MODEL_FUNCTIONS_AND_TYPES__

#include "errors.h"
#include "paint.h"
#include "process.h"
#include "vertices.h"
#include "faces.h"

/**
 * \brief Type for storing model
 */
typedef struct
{
    vertices_t vertices;
    faces_t faces;
} model_t;

/**
 * \brief Allocate model
 *
 * \param model
 * \param vertices_count
 * \param faces_count
 */
void AllocateModel(model_t& model, int& vertices_count, int& faces_count);
/**
 * \brief Initialize model
 *
 * \param filename
 * \return
 */
model_t &InitModel(void);
/**
 * \brief Load model from file
 *
 * \param filename
 * \param model
 * \return
 */
errors LoadModel(model_t& model, const char* filename);
/**
 * \brief Draw model
 *
 * \param model
 * \param canvas
 * \return
 */
errors DrawModel(const model_t& model, canvas_t& canvas);
/**
* \brief Transfer model
*
* \param model
* \param t_coord
* \return
*/
errors TransferModel(model_t& model, const transfer_t& t_coord);
/**
 * \brief Rotate model
 *
 * \param model
 * \param r_angles
 * \return
 */
errors RotateModel(model_t& model, const rotate_t& r_angles);
/**
 * \brief Scale model
 *
 * \param model
 * \param s_coeff
 * \return
 */
errors ScaleModel(model_t& model, const scale_t& s_coeff);
/**
 * \brief Free model
 *
 * \param filename
 * \return
 */
void FreeModel(model_t& model);

#endif // __MODEL_FUNCTIONS_AND_TYPES__
