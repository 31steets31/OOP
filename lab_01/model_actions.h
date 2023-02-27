#ifndef __MODEL_ACTIONS__
#define __MODEL_ACTIONS__

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

#endif // __MODEL_ACTIONS__
