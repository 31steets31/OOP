#ifndef __PROCESS__
#define __PROCESS__

#include "errors.h"
#include "paint.h"
#include "defines.h"
#include "process.h"

/**
 * \brief Allowed actions
 */
enum actions
{
	LOAD_MODEL,
	DESTROY_MODEL,
	DRAW_MODEL,
	TRANSFER_MODEL,
	ROTATE_MODEL,
	SCALE_MODEL,
};

/**
 * \brief Offsets for transfer
 */
struct transfer_t
{
	double dx;
	double dy;
	double dz;
};

/**
 * \brief Coordinates and angles for rotation
 */
struct rotate_t
{
	double x_center;
	double y_center;
	double z_center;

	double x_angle;
	double y_angle;
	double z_angle;
};

/**
 * \brief Coordinates and coefficients for scaling
 */
struct scale_t
{
	double x_center;
	double y_center;
	double z_center;

	double kx;
	double ky;
	double kz;
};

/**
 * \brief Options for processing
 */
struct options_t
{
	actions action;
	union
	{
		char filename[MAX_FILENAME_LEN + 1];
		canvas_t canvas;
		transfer_t t_coord;
		rotate_t r_angles;
		scale_t s_coeff;
	};
};

/**
 * \brief Process command
 *
 * \param opt
 * \return 
 */
errors Process(options_t& opt);

#endif // __PROCESS__


