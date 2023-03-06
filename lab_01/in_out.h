#ifndef __IN_OUT__
#define __IN_OUT__

#include <iostream>

#include "errors.h"
#include "model.h"
#include "points.h"
#include "faces.h"
#include "vertices.h"

/**
 * \brief Read vertices count
 *
 * \param vertices_count
 * \param file
 * \return
 */
errors ReadVerticesCount(int& vertices_count, FILE* file);
/**
 * \brief Read faces count
 *
 * \param faces_count
 * \param file
 * \return
 */
errors ReadFacesCount(int& faces_count, FILE* file);
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
 * \brief Read all vertices
 *
 * \param vertices
 * \param count
 * \param file
 * \return
 */
errors ReadAllVertices(point_t* vertices, int& count, FILE* file);
/**
 * \brief Read all faces
 *
 * \param faces
 * \param count
 * \param file
 * \return
 */
errors ReadAllFaces(face_t* faces, int& count, FILE* file);
/**
 * \brief Read vertices
 *
 * \param vertices
 * \param file
 * \return
 */
errors ReadVertices(vertices_t& vertices, FILE* file);
/**
 * \brief Read faces
 *
 * \param faces
 * \param file
 * \return
 */
errors ReadFaces(faces_t& faces, FILE* file);
/**
 * \brief Read model data
 *
 * \param file
 * \param vertices
 * \param faces
 * \return
 */
errors ReadModel(model_t& model, FILE* file);
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
