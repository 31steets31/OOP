#include <iostream>
#include <QMessageBox>

#include "in_out.h"
#include "model.h"
#include "defines.h"
#include "errors.h"

/**
 * \brief Get vertices and faces count
 * 
 * \param file
 * \param vertices
 * \param faces
 */
void GetCount(FILE *file, int& vertices, int& faces)
{
    // Set buffer
    char line[MAX_STR_LEN + 1];
    memset(line, 0, MAX_STR_LEN + 1);

    // Calculate count
    while (fgets(line, MAX_STR_LEN + 1, file) != NULL)
    {
        if (line[0] == 'v')
            ++vertices;
        else if (line[0] == 'f')
            ++faces;
    }

    rewind(file);
}

/**
 * \brief Get vertices from line
 * 
 * \param line
 * \param vertex
 * \return 
 */
int GetVertexFromLine(const char *line, vertex_t &vertex)
{
    return sscanf(line, "v %lf %lf %lf",
        &(vertex.x),
        &(vertex.y),
        &(vertex.z));
}

/**
 * \brief Get faces from line
 * 
 * \param line
 * \param face
 * \return 
 */
int GetFacesFromLine(const char* line, face_t& face)
{
    return sscanf(line, "f %d %d",
        &(face.a),
        &(face.b));
}

/**
 * \brief Read model from file
 * 
 * \param file
 * \param vertexes
 * \param faces
 * \return 
 */
errors ReadModel(FILE *file, vertexes_t &vertexes, faces_t &faces)
{
    // Set buffer
    char line[MAX_STR_LEN + 1];
    memset(line, 0, MAX_STR_LEN + 1);

    // Read data
    int r_count;

    for (int i = 0, j = 0; fgets(line, MAX_STR_LEN + 1, file) != NULL; )
    {
        if (line[0] == 'v')
        {
            r_count = GetVertexFromLine(line, vertexes.points[i]);

            if (r_count != 3)
                return ERR_READING_FILE;

            ++i;
        }
        else if (line[0] == 'f')
        {
            r_count = GetFacesFromLine(line, faces.arr[j]);

            if (r_count != 2)
                return ERR_READING_FILE;

            ++j;
        }
    }
}

/**
 * \brief Load model from file
 * 
 * \param filename
 * \param model
 * \return 
 */
errors LoadModel(model_t &model, const char *filename)
{
    // Return code
    errors rc = ERR_SUCCESS;

    // Read file
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        FreeModel(model);
        return ERR_OPEN_FILE;
    }

    // Get vertices and faces count
    int n_vertices = 0;
    int n_faces = 0;

    GetCount(file, n_vertices, n_faces);

    // Allocate memory for vertices and faces
    AllocateVertices(model.vertices, n_vertices);
    AllocateFaces(model.faces, n_faces);

    // Read vertices and faces
    rc = ReadModel(file, model.vertices, model.faces);
    if (rc != ERR_SUCCESS)
    {
        fclose(file);
        FreeModel(model);
        return rc;
    }

    fclose(file);
    
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
		case ERR_READING_FILE:
        {
            QMessageBox::critical(NULL, "Error", "Can't read file");
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
            break;
    }
}
