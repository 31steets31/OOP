#include <iostream>
#include <QMessageBox>

#include "in_out.h"
#include "model.h"
#include "defines.h"
#include "errors.h"

/**
 * \brief Load model from file
 * 
 * \param filename
 * \return 
 */
errors LoadModel(model_t &model, const char *filename)
{
    // Read file
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        FreeModel(model);
        return ERR_OPEN_FILE;
    }

    int n_vertices = 0;
    int n_faces = 0;

    char line[MAX_STR_LEN + 1];
    memset(line, 0, MAX_STR_LEN + 1);

    while (fgets(line, MAX_STR_LEN + 1, file) != NULL)
    {
        if (line[0] == 'v')
            ++n_vertices;
        else if (line[0] == 'f')
            ++n_faces;
    }

    // Allocate memory for vertices and faces
    model.n_vertices = n_vertices;
    model.n_faces = n_faces;
    model.vertices = (vertex_t *) malloc(sizeof(vertex_t) * n_vertices);
    model.faces = (face_t *) malloc(sizeof(face_t) * n_faces);

    rewind(file);

    int i = 0, j = 0;
    int rc;

    // Read vertices and faces
    while (fgets(line, 128, file) != NULL)
    {
        if (line[0] == 'v')
        {
            rc = sscanf(line, "v %lf %lf %lf",
                   &(model.vertices[i].x),
                   &(model.vertices[i].y),
                   &(model.vertices[i].z));

            if (rc != 3)
            {
				FreeModel(model);
                fclose(file);
				return ERR_READING_FILE;
			}

            ++i;
        }
        else if (line[0] == 'f')
        {
            rc = sscanf(line, "f %d %d",
                   &(model.faces[j].a),
                   &(model.faces[j].b));

            if (rc != 2)
            {
                FreeModel(model);
                fclose(file);
                return ERR_READING_FILE;
            }

            ++j;
        }
    }

    fclose(file);
    
    return ERR_SUCCESS;
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
