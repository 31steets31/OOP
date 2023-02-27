#include "point.h"
#include "process.h"

/**
 * \brief Transfer point
 *
 * \param point
 * \param t_coord
 */
void TransferPoint(point_t& point, const transfer_t& t_coord)
{
	point.x += t_coord.dx;
	point.y += t_coord.dy;
	point.z += t_coord.dz;
}

/**
 * \brief Rotate point around Oy and Oz
 *
 * \param point
 * \param r_angles
 */
void RotatePointYZ(point_t& point, const rotate_t& r_angles)
{
	point.y = r_angles.y_center +
		(point.y - r_angles.y_center) *
		cos(r_angles.x_angle * M_PI / 180.0) -
		(point.z - r_angles.z_center) *
		sin(r_angles.x_angle * M_PI / 180.0);

	point.z = r_angles.z_center +
		(point.y - r_angles.y_center) *
		sin(r_angles.x_angle * M_PI / 180.0) +
		(point.z - r_angles.z_center) *
		cos(r_angles.x_angle * M_PI / 180.0);
}

/**
 * \brief Rotate point around Ox and Oz
 *
 * \param point
 * \param r_angles
 */
void RotatePointXZ(point_t& point, const rotate_t& r_angles)
{
	point.x = r_angles.x_center + (point.x - r_angles.x_center) *
		cos(r_angles.y_angle * M_PI / 180.0) +
		(point.z - r_angles.z_center) *
		sin(r_angles.y_angle * M_PI / 180.0);

	point.z = r_angles.z_center - (point.x - r_angles.x_center) *
		sin(r_angles.y_angle * M_PI / 180.0) +
		(point.z - r_angles.z_center) *
		cos(r_angles.y_angle * M_PI / 180.0);
}

/**
 * \brief Rotate point around Ox and Oy
 *
 * \param point
 * \param r_angles
 */
void RotatePointXY(point_t& point, const rotate_t& r_angles)
{
	point.x = r_angles.x_center + (point.x - r_angles.x_center) *
		cos(r_angles.z_angle * M_PI / 180.0) -
		(point.y - r_angles.y_center) *
		sin(r_angles.z_angle * M_PI / 180.0);

	point.y = r_angles.y_center + (point.x - r_angles.x_center) *
		sin(r_angles.z_angle * M_PI / 180.0) +
		(point.y - r_angles.y_center) *
		cos(r_angles.z_angle * M_PI / 180.0);
}

/**
 * \brief Scale point
 *
 * \param point
 * \param s_coeff
 */
void ScalePoint(point_t& point, const scale_t& s_coeff)
{
	point.x = s_coeff.x_center + (point.x - s_coeff.x_center) * s_coeff.kx;
	point.y = s_coeff.y_center + (point.y - s_coeff.y_center) * s_coeff.ky;
	point.z = s_coeff.z_center + (point.z - s_coeff.z_center) * s_coeff.kz;
}