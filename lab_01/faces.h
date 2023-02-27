#ifndef __FACES_FUNCTIONS_AND_TYPES__
#define __FACES_FUNCTIONS_AND_TYPES__

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
void AllocateFaces(faces_t& faces, int& count);
/**
 * \brief Free faces
 *
 * \param faces
 */
void FreeFaces(faces_t& faces);

#endif // __FACES_FUNCTIONS_AND_TYPES__
