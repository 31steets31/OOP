#include <iostream>

#include "in_out.h"
#include "model.h"
#include "defines.h"

/**
 * \brief Load model from file
 * 
 * \param filename
 * \return 
 **/
model_t *LoadModel(const char *filename)
{
    // Create model
    model_t *model = (model_t *) malloc(sizeof(model_t));

    if (!model)
		return NULL;

	model->n_vertices = 0;
	model->n_faces = 0;
	model->vertices = NULL;
	model->faces = NULL;

    // Read file
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        free(model);
        return NULL;
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
    model->n_vertices = n_vertices;
    model->n_faces = n_faces;
    model->vertices = (vertex_t *) malloc(sizeof(vertex_t) * n_vertices);
    model->faces = (face_t *) malloc(sizeof(face_t) * n_faces);

    rewind(file);

    int i = 0, j = 0;
    int rc;

    // Read vertices and faces
    while (fgets(line, 128, file) != NULL)
    {
        if (line[0] == 'v')
        {
            rc = sscanf(line, "v %f %f %f",
                   &(model->vertices[i].x),
                   &(model->vertices[i].y),
                   &(model->vertices[i].z));

            if (rc != 3)
            {
				FreeModel(model);
                fclose(file);
				return NULL;
			}

            ++i;
        }
        else if (line[0] == 'f')
        {
            rc = sscanf(line, "f %d %d %d",
                   &(model->faces[j].a),
                   &(model->faces[j].b),
                   &(model->faces[j].c));

            if (rc != 3)
            {
                FreeModel(model);
                fclose(file);
                return NULL;
            }

            ++j;
        }
    }

    fclose(file);
    
    return model;
}