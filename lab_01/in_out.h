#ifndef __IN_OUT__
#define __IN_OUT__

#include <iostream>

#include "errors.h"
#include "model.h"
#include "point.h"
#include "faces.h"
#include "vertices.h"

/**
 * \brief Read vertices and faces count
 *
 * \param file
 * \param vertices_count
 * \param faces_count
 * \return
 */
errors ReadCounts(FILE* file, int& vertices_count, int& faces_count);
/**
 * \brief Read one vertex
 *
 * \param file
 * \param vertex
 * \return
 */
errors ReadVertex(FILE* file, point_t& vertex);
/**
 * \brief Read one face
 *
 * \param file
 * \param face
 * \return
 */
errors ReadFace(FILE* file, face_t& face);
/**
 * \brief Read model data
 *
 * \param file
 * \param vertices
 * \param faces
 * \return
 */
errors ReadModel(FILE* file, vertices_t& vertices, faces_t& faces);
/**
 * \brief Print author information
 */
void PrintAuthorInfo(void);
/**
 * \brief Print program information
 */
void PrintProgramInfo(void);
/**
 * \brief Print error message
 *
 * \param err
 */
void PrintErrorMessage(const errors& err);

#endif // __IN_OUT__
