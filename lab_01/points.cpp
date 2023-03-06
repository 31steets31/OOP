#include "points.h"
#include "process.h"

/**
 * \brief Transform angle to radians
 * 
 * \param angle
 * \return 
 */
static inline double ToRadians(const double& angle)
{
	return angle * M_PI / 180;
}

/**
 * \brief Project point
 *
 * \param a
 */
void ProjectPoint(project_point_t& project_point, point_t& a)
{
	a.x += CANVAS_WIDTH / 2;
	a.y = -a.y + CANVAS_HEIGHT / 2;

	project_point.x = a.x;
	project_point.y = a.y;
}

/**
 * \brief Get point by index
 *
 * \param points
 * \param index
 * \return
 */
point_t GetPointByIndex(point_t* points, int& index)
{
	return points[index];
}

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
 * \brief Transfer points
 *
 * \param points
 * \param points_count
 * \param t_coord
 */
void TransferPoints(point_t* points, const int& points_count, const transfer_t& t_coord)
{
	for (int i = 0; i < points_count; ++i)
		TransferPoint(points[i], t_coord);
}

/**
 * \brief Rotate point around Ox
 *
 * \param point
 * \param angle
 */
void RotatePointYZ(point_t& point, const double& angle)
{
	double sin_angle = sin(ToRadians(angle));
	double cos_angle = cos(ToRadians(angle));

	double temp_y = point.y;

	point.y = point.y * cos_angle + point.z * sin_angle;
	point.z = -temp_y * sin_angle + point.z * cos_angle;
}

/**
 * \brief Rotate point around Oy
 *
 * \param point
 * \param angle
 */
void RotatePointXZ(point_t& point, const double& angle)
{
	double sin_angle = sin(ToRadians(angle));
	double cos_angle = cos(ToRadians(angle));

	double temp_x = point.x;

	point.x = point.x * cos_angle + point.z * sin_angle;
	point.z = -temp_x * sin_angle + point.z * cos_angle;
}

/**
 * \brief Rotate point around Oz
 *
 * \param point
 * \param angle
 */
void RotatePointXY(point_t& point, const double& angle)
{
	double sin_angle = sin(ToRadians(angle));
	double cos_angle = cos(ToRadians(angle));

	double temp_x = point.x;

	point.x = point.x * cos_angle + point.y * sin_angle;
	point.y = -temp_x * sin_angle + point.y * cos_angle;
}

/**
 * \brief Rotate points
 * 
 * \param points
 * \param points_count
 * \param r_angles
 */
void RotatePoints(point_t* points, const int& points_count, const rotate_t& r_angles)
{
	transfer_t d_point;

	for (int i = 0; i < points_count; ++i)
	{
		d_point.dx = r_angles.x_center;
		d_point.dy = r_angles.y_center;
		d_point.dz = r_angles.z_center;

		TransferPoint(points[i], d_point);

		// Rotate around center point r_angles.x_center, r_angles.y_center, r_angles.z_center
		RotatePointYZ(points[i], r_angles.x_angle);

		RotatePointXZ(points[i], r_angles.y_angle);

		RotatePointXY(points[i], r_angles.z_angle);

		d_point.dx = -r_angles.x_center;
		d_point.dy = -r_angles.y_center;
		d_point.dz = -r_angles.z_center;

		TransferPoint(points[i], d_point);
	}
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

/**
 * \brief Scale points
 * 
 * \param points
 * \param points_count
 * \param s_coeff
 */
void ScalePoints(point_t* points, const int& points_count, const scale_t& s_coeff)
{
	for (int i = 0; i < points_count; ++i)
		// Scale coordinates around center point s_coeff.x_center, s_coeff.y_center, s_coeff.z_center
		ScalePoint(points[i], s_coeff);
}
