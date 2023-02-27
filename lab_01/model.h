#ifndef __MODEL_FUNCTIONS_AND_TYPES__
#define __MODEL_FUNCTIONS_AND_TYPES__

#include "errors.h"
#include "paint.h"
#include "process.h"

/**
 * \brief Type for storing vertex coordinates
 */
struct vertex_t
{
    double x;
    double y;
    double z;
};

/**
 * \brief Type for storing face indices
 */
struct face_t
{
    int a;
    int b;
};

/**
 * \brief Vertexes
 */
struct vertexes_t
{
    vertex_t* points;
    int n_vertices;
};

/**
 * \brief Faces
 */
struct faces_t
{
    face_t* arr;
    int n_faces;
};

/**
 * \brief Type for storing model
 */
typedef struct
{
    vertexes_t vertices;
    faces_t faces;
} model_t;

/**
 * \brief Initialize vertices
 *
 * \return
 */
void InitVertices(vertexes_t& vertices);
/**
 * \brief Allocate vertices
 *
 * \param vertices
 * \param count
 */
void AllocateVertices(vertexes_t& vertices, int& count);
/**
 * \brief Initialize faces
 *
 * \return
 */
void InitFaces(faces_t& faces);
/**
 * \brief Allocate faces
 *
 * \param faces
 * \param count
 */
void AllocateFaces(faces_t& faces, int& count);
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
 * \brief Transfer point
 *
 * \param point
 * \param t_coord
 */
void TransferPoint(vertex_t& point, const transfer_t& t_coord);
/**
 * \brief Transfer vertices
 *
 * \param vertices
 * \param t_coord
 */
void TransferVertices(vertexes_t& vertices, const transfer_t& t_coord);
/**
* \brief Transfer model
*
* \param model
* \param t_coord
* \return
*/
errors TransferModel(model_t& model, const transfer_t& t_coord);
/**
 * \brief Rotate point around Oy and Oz
 *
 * \param point
 * \param r_angles
 */
void RotatePointYZ(vertex_t& point, const rotate_t& r_angles);
/**
 * \brief Rotate point around Ox and Oz
 *
 * \param point
 * \param r_angles
 */
void RotatePointXZ(vertex_t& point, const rotate_t& r_angles);
/**
 * \brief Rotate point around Ox and Oy
 *
 * \param point
 * \param r_angles
 */
void RotatePointXY(vertex_t& point, const rotate_t& r_angles);
/**
 * \brief Rotate model
 *
 * \param model
 * \param r_angles
 * \return
 */
errors RotateModel(model_t& model, const rotate_t& r_angles);
/**
 * \brief Scale point
 *
 * \param point
 * \param s_coeff
 */
void ScalePoint(vertex_t& point, const scale_t& s_coeff);
/**
 * \brief Scale vertices
 *
 * \param vertices
 * \param s_coeff
 */
void ScaleVertices(vertexes_t& vertices, const scale_t& s_coeff);
/**
 * \brief Scale model
 *
 * \param model
 * \param s_coeff
 * \return
 */
errors ScaleModel(model_t& model, const scale_t& s_coeff);
/**
 * \brief Free verticles
 *
 * \param vertices
 */
void FreeVertices(vertexes_t& vertices);
/**
 * \brief Free faces
 *
 * \param faces
 */
void FreeFaces(faces_t& faces);
/**
 * \brief Free model
 *
 * \param filename
 * \return
 */
void FreeModel(model_t& model);

#endif // __MODEL_FUNCTIONS_AND_TYPES__
