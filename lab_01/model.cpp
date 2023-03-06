#include <iostream>

#include "model.h"
#include "faces.h"
#include "vertices.h"
#include "in_out.h"

/**
 * \brief Initialize model
 *
 * \return
 */
model_t& InitModel(void)
{
	static model_t model;

	// Initialize vertices
	InitVertices(model.vertices);

	// Initialize vertices
	InitFaces(model.faces);

	return model;
}

/**
 * \brief Allocate model
 * 
 * \param model
 * \param vertices_count
 * \param faces_count
 */
errors AllocateModel(model_t& model, int& vertices_count, int& faces_count)
{
	// Return code
	errors rc = ERR_SUCCESS;

	// Allocate vertices
	rc = AllocateVertices(model.vertices, vertices_count);

	if (rc == ERR_SUCCESS)
	{
		// Allocate faces
		rc = AllocateFaces(model.faces, faces_count);

		if (rc != ERR_SUCCESS)
			FreeVertices(model.vertices);
	}

	return rc;
}

/**
 * \brief Copy model from src to dst
 * 
 * \param src
 * \param dst
 */
void CopyModel(model_t& dst, const model_t& src)
{
	dst = src;
}

/**
 * \brief Load model from file
 *
 * \param filename
 * \param model
 * \return
 */
errors LoadModel(model_t& model, const char* filename)
{
	// Return code
	errors rc = ERR_SUCCESS;

	// Open file
	FILE* file = fopen(filename, "r");

	if (!file)
	{
		rc = ERR_OPEN_FILE;
		return rc;
	}

	// Create buffer model
	model_t buf_model;

	rc = ReadModel(buf_model, file);

	if (rc == ERR_SUCCESS)
	{
		FreeModel(model);
		CopyModel(model, buf_model);
	}

	return rc;
}

/**
 * \brief Draw model
 *
 * \param model
 * \param canvas
 * \return
 */
errors DrawModel(model_t &model, canvas_t &canvas)
{
	// Clear canvas
	ClearCanvas(canvas);

	// Draw model
	AddLines(canvas, model.vertices, model.faces);

	return ERR_SUCCESS;
}

/**
 * \brief Transfer model
 * 
 * \param model
 * \param t_coord
 * \return 
 */
errors TransferModel(model_t& model, const transfer_t& t_coord)
{
	// Transfer vertices
	TransferVertices(model.vertices, t_coord);

	return ERR_SUCCESS;
}

/**
 * \brief Rotate model
 * 
 * \param model
 * \param r_angles
 * \return 
 */
errors RotateModel(model_t& model, const rotate_t& r_angles)
{
	// Rotate vertices
	RotateVertices(model.vertices, r_angles);

	return ERR_SUCCESS;
}

/**
 * \brief Scale model
 * 
 * \param model
 * \param s_coeff
 * \return 
 */
errors ScaleModel(model_t& model, const scale_t& s_coeff)
{
	// Scale vertices
	ScaleVertices(model.vertices, s_coeff);

	return ERR_SUCCESS;
}

/**
 * \brief Free model
 *
 * \param model
 * \return
 */
void FreeModel(model_t &model)
{
	// Free vertices
	FreeVertices(model.vertices);

	// Free faces
	FreeFaces(model.faces);
}