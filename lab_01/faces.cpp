#include "faces.h"

#include <iostream>

/**
 * \brief Initialize faces
 *
 * \return
 */
void InitFaces(faces_t& faces)
{
	faces.n_faces = 0;
	faces.arr = NULL;
}

/**
 * \brief Allocate faces
 *
 * \param faces
 * \param count
 */
void AllocateFaces(faces_t& faces, int& count)
{
	faces.n_faces = count;
	faces.arr = (face_t *) malloc(sizeof(face_t) * count);
}

/**
 * \brief Free faces
 *
 * \param faces
 */
void FreeFaces(faces_t& faces)
{
	free(faces.arr);
}