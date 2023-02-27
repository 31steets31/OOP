#ifndef __PROCESS__
#define __PROCESS__

#include "paint.h"
#include "defines.h"

enum actions
{
	LOAD_MODEL,
	DESTROY_MODEL,
	DRAW_MODEL,
	TRANSFER_MODEL,
	ROTATE_MODEL,
	SCALE_MODEL,
};

struct transfer_t
{
	double dx;
	double dy;
	double dz;
};

struct rotate_t
{
	double x_center;
	double y_center;
	double z_center;

	double x_angle;
	double y_angle;
	double z_angle;
};

struct scale_t
{
	double x_center;
	double y_center;
	double z_center;

	double kx;
	double ky;
	double kz;
};

typedef struct
{
	actions action;
	union
	{
		char filename[MAX_FILENAME_LEN + 1];
		canvas_t canvas;
		transfer_t t_coord;
		rotate_t r_angles;
		scale_t s_coeff;
	} params;
} options_t;

/**
 * \brief Process command
 *
 * \param opt
 * \return 
 */
errors Process(options_t& opt);

#endif // __PROCESS__


