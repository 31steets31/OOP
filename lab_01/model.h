#ifndef MODEL_FUNCTIONS_AND_TYPES
#define MODEL_FUNCTIONS_AND_TYPES

/**
 * \brief Type for storing vertex coordinates
 **/
typedef struct
{
    float x;
    float y;
    float z;
} vertex_t;

/**
 * \brief Type for storing face indices
 **/
typedef struct
{
    int a;
    int b;
    int c;
} face_t;

/**
 * \brief Type for storing model
 **/
typedef struct model_t
{
    int n_vertices;
    int n_faces;
    vertex_t* vertices;
    face_t* faces;
} model_t;

static model_t *model;

/**
 * \brief Free model
 *
 * \param filename
 * \return
 **/
void FreeModel(model_t *model);

#endif // MODEL_FUNCTIONS_AND_TYPES
