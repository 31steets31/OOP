#ifndef __MODEL_FUNCTIONS_AND_TYPES__
#define __MODEL_FUNCTIONS_AND_TYPES__

#include "errors.h"
#include "paint.h"

/**
 * \brief Type for storing vertex coordinates
 */
typedef struct
{
    double x;
    double y;
    double z;
} vertex_t;

/**
 * \brief Type for storing face indices
 */
typedef struct
{
    int a;
    int b;
} face_t;

/**
 * \brief Type for storing model
 */
typedef struct
{
    int n_vertices;
    int n_faces;
    vertex_t* vertices;
    face_t* faces;
} model_t;

/**
 * \brief Initialize model
 *
 * \param filename
 * \return
 */
model_t &InitModel(void);
/**
 * \brief Draw model
 *
 * \param model
 * \param canvas
 * \return
 */
errors DrawModel(const model_t& model, canvas_t& canvas);
/**
 * \brief Free model
 *
 * \param filename
 * \return
 */
void FreeModel(model_t& model);


#endif // __MODEL_FUNCTIONS_AND_TYPES__
