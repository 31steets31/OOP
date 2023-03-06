#ifndef __IN_OUT__
#define __IN_OUT__

#include <iostream>

#include "errors.h"
#include "model.h"
#include "points.h"
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
errors ReadCounts(int& vertices_count, int& faces_count, FILE* file);
/**
 * \brief Read one vertex
 *
 * \param file
 * \param vertex
 * \return
 */
errors ReadVertex(point_t& vertex, FILE* file);
/**
 * \brief Read one face
 *
 * \param file
 * \param face
 * \return
 */
errors ReadFace(face_t& face, FILE* file);
/**
 * \brief Read model data
 *
 * \param file
 * \param vertices
 * \param faces
 * \return
 */
errors ReadModel(vertices_t& vertices, faces_t& faces, FILE* file);
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
