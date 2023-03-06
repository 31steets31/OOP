#ifndef __FACES_FUNCTIONS_AND_TYPES__
#define __FACES_FUNCTIONS_AND_TYPES__

#include "errors.h"

/**
 * \brief Type for storing face indices
 */
struct face_t
{
    int a;
    int b;
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
errors AllocateFaces(faces_t& faces, int& count);
/**
 * \brief Get face by index
 *
 * \param faces
 * \param index
 * \return
 */
face_t GetFaceByIndex(face_t* faces, int& index);
/**
 * \brief Free faces
 *
 * \param faces
 */
void FreeFaces(faces_t& faces);

#endif // __FACES_FUNCTIONS_AND_TYPES__
