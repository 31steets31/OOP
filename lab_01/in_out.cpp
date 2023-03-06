#include <iostream>
#include <QMessageBox>

#include "in_out.h"
#include "model.h"
#include "defines.h"
#include "errors.h"
#include "vertices.h"
#include "faces.h"

/**
 * \brief Read vertices count
 * 
 * \param vertices_count
 * \param file
 * \return 
 */
errors ReadVerticesCount(int& vertices_count, FILE* file)
{
    // Return code
    errors rc = ERR_SUCCESS;

    // Read counts
    int read_count = fscanf(file, "v: %d\n", &vertices_count);

    if (read_count != 1)
        rc = ERR_GET_COUNTS;

    return rc;
}

/**
 * \brief Read faces count
 *
 * \param vertices_count
 * \param file
 * \return
 */
errors ReadFacesCount(int& faces_count, FILE* file)
{
    // Return code
    errors rc = ERR_SUCCESS;

    // Read counts
    int read_count = fscanf(file, "f: %d\n", &faces_count);

    if (read_count != 1)
        rc = ERR_GET_COUNTS;

    return rc;
}

/**
 * \brief Read one vertex
 * 
 * \param file
 * \param vertex
 * \return 
 */
errors ReadVertex(point_t& vertex, FILE* file)
{
    // Return code
    errors rc = ERR_SUCCESS;

    // Read point
    int read_count = fscanf(file, "%lf %lf %lf\n",
        &(vertex.x),
        &(vertex.y),
        &(vertex.z));

    if (read_count != 3)
        rc = ERR_READING_FILE;

    return rc;
}

/**
 * \brief Read one face
 *
 * \param file
 * \param face
 * \return
 */
errors ReadFace(face_t& face, FILE* file)
{
    // Return code
    errors rc = ERR_SUCCESS;

    // Read point
    int read_count = fscanf(file, "%d %d\n",
        &(face.a),
        &(face.b));

    if (read_count != 2)
        rc = ERR_READING_FILE;

    return rc;
}

/**
 * \brief Read all vertices
 * 
 * \param vertices
 * \param count
 * \param file
 * \return 
 */
errors ReadAllVertices(point_t* vertices, int& count, FILE* file)
{
    // Return code
    errors rc = ERR_SUCCESS;

    for (int i = 0; rc == ERR_SUCCESS && i < count; ++i)
        rc = ReadVertex(vertices[i], file);

    return rc;
}

/**
 * \brief Read all faces
 *
 * \param faces
 * \param count
 * \param file
 * \return
 */
errors ReadAllFaces(face_t* faces, int& count, FILE* file)
{
    // Return code
    errors rc = ERR_SUCCESS;

    for (int i = 0; rc == ERR_SUCCESS && i < count; ++i)
        rc = ReadFace(faces[i], file);

    return rc;
}

/**
 * \brief Read vertices
 * 
 * \param vertices
 * \param file
 * \return 
 */
errors ReadVertices(vertices_t& vertices, FILE* file)
{
    // Return code
    errors rc = ERR_SUCCESS;

    rc = ReadVerticesCount(vertices.n_vertices, file);

    if (rc == ERR_SUCCESS)
    {
        rc = AllocateVertices(vertices, vertices.n_vertices);

        if (rc == ERR_SUCCESS)
        {
            rc = ReadAllVertices(vertices.points, vertices.n_vertices, file);

            if (rc != ERR_SUCCESS)
                FreeVertices(vertices);
        }
    }

    return rc;
}

/**
 * \brief Read faces
 *
 * \param faces
 * \param file
 * \return
 */
errors ReadFaces(faces_t& faces, FILE* file)
{
    // Return code
    errors rc = ERR_SUCCESS;

    rc = ReadFacesCount(faces.n_faces, file);

    if (rc == ERR_SUCCESS)
    {
        rc = AllocateFaces(faces, faces.n_faces);

        if (rc == ERR_SUCCESS)
        {
            rc = ReadAllFaces(faces.arr, faces.n_faces, file);

            if (rc != ERR_SUCCESS)
                FreeFaces(faces);
        }
    }

    return rc;
}

/**
 * \brief Read model data
 * 
 * \param file
 * \param vertices
 * \param faces
 * \return 
 */
errors ReadModel(model_t& model, FILE* file)
{
    // Return code
    errors rc = ERR_SUCCESS;

    // Read vertices
    rc = ReadVertices(model.vertices, file);

    if (rc == ERR_SUCCESS)
    {
        // Read faces
        rc = ReadFaces(model.faces, file);

        if (rc != ERR_SUCCESS)
            FreeVertices(model.vertices);
    }

    return rc;
}

/**
 * \brief Print author information
 */
void PrintAuthorInfo(void)
{
    QMessageBox::information(
        NULL, 
        "Author information", 
        "Stepan Postnov, ICS7-41B.");
}

/**
 * \brief Print program information
 */
void PrintProgramInfo(void)
{
    QMessageBox::information(
		NULL, 
		"Program information", 
		"This program is intended for drawing 3D models.\n "
        "It allows you to translate, rotate and scale.");
}

/**
 * \brief Print error message
 * 
 * \param err
 */
void PrintErrorMessage(const errors &err)
{
    switch (err)
    {
        case ERR_FILENAME_LEN:
        {
            QMessageBox::critical(NULL, "Error", "Incorrect filename length");
            break;
        }
        case ERR_ALLOCATE:
        {
            QMessageBox::critical(NULL, "Error", "No free memory");
            break;
        }
        case ERR_OPEN_FILE:
        {
			QMessageBox::critical(NULL, "Error", "Can't open file");
			break;
		}
        case ERR_GET_COUNTS:
        {
            QMessageBox::critical(NULL, "Error", "Can't read file"
                "Incorrect counts");
            break;
        }
		case ERR_READING_FILE:
        {
            QMessageBox::critical(NULL, "Error", "Can't read file"
                "Incorrect data");
            break;
        }
        case ERR_INCORRECT_COORDINATES:
        {
			QMessageBox::critical(NULL, "Error", "Incorrect coordinates");
			break;
		}
        case ERR_INCORRECT_OFFSET:
        {
            QMessageBox::critical(NULL, "Error", "Incorrect offsets");
            break;
        }
        case ERR_INCORRECT_ANGLES:
        {
			QMessageBox::critical(NULL, "Error", "Incorrect angles");
			break;
		}
        case ERR_INCORRECT_CENTER:
        {
			QMessageBox::critical(NULL, "Error", "Incorrect center");
			break;
		}
        case ERR_INCORRECT_COEFFICIENTS:
        {
            QMessageBox::critical(NULL, "Error", "Incorrect coefficients");
            break;
        }
        default:
        {
            QMessageBox::critical(NULL, "Error", "Unknown error");
            break;
        }
    }
}
