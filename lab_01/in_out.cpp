#include <iostream>
#include <QMessageBox>

#include "in_out.h"
#include "model.h"
#include "defines.h"
#include "errors.h"

/**
 * \brief Read vertices and faces count
 * 
 * \param file
 * \param vertices_count
 * \param faces_count
 * \return 
 */
errors ReadCounts(FILE* file, int& vertices_count, int& faces_count)
{
    // Return code
    errors rc = ERR_SUCCESS;

    // Read counts
    int read_count = fscanf(file, "v: %d; f: %d\n", &vertices_count, &faces_count);

    if (read_count != 2)
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
errors ReadVertex(FILE* file, point_t& vertex)
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
errors ReadFace(FILE* file, face_t& face)
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
 * \brief Read model data
 * 
 * \param file
 * \param vertices
 * \param faces
 * \return 
 */
errors ReadModel(FILE* file, vertices_t& vertices, faces_t& faces)
{
    // Return code
    errors rc = ERR_SUCCESS;

    // Read data
    char type;

    int i = 0, j = 0;

    while (feof(file) == 0)
    {
        // Get type of data in line
        type = getc(file);

        if (type == 'v' && i < vertices.n_vertices)
            rc = ReadVertex(file, vertices.points[i++]);
        else if (type == 'f' && j < faces.n_faces)
            rc = ReadFace(file, faces.arr[j++]);
        else
            rc = ERR_READING_FILE;

        if (rc != ERR_SUCCESS)
            break;
    }

    if (rc == ERR_SUCCESS &&
        (vertices.n_vertices != i || faces.n_faces != j))
        rc = ERR_READING_FILE;

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
        case ERR_OPEN_FILE:
        {
			QMessageBox::critical(NULL, "Error", "Can't open file");
			break;
		}
        case ERR_GET_COUNTS:
        {
            QMessageBox::critical(NULL, "Error", "Can't read file. \n"
                "Incorrect counts");
            break;
        }
		case ERR_READING_FILE:
        {
            QMessageBox::critical(NULL, "Error", "Can't read file\n"
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
