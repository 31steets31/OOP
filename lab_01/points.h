#ifndef __POINT_FUNCTIONS_AND_TYPES__
#define __POINT_FUNCTIONS_AND_TYPES__

#include "model_actions.h"

/**
 * \brief Point type
 */
struct point_t
{
    double x;
    double y;
    double z;
};


/**
 * \brief Transform angle to radians
 *
 * \param angle
 * \return
 */
static inline double ToRadians(const double& angle);
/**
 * \brief Transfer point
 *
 * \param point
 * \param t_coord
 */
void TransferPoint(point_t& point, const transfer_t& t_coord);/**
 * \brief Transfer points
 *
 * \param points
 * \param points_count
 * \param t_coord
 */
void TransferPoints(point_t* points, const int& points_count, const transfer_t& t_coord);
/**
 * \brief Rotate point around Ox
 *
 * \param point
 * \param angle
 */
void RotatePointYZ(point_t& point, const double& angle);
/**
 * \brief Rotate point around Oy
 *
 * \param point
 * \param angle
 */
void RotatePointXZ(point_t& point, const double& angle);
/**
 * \brief Rotate point around Oz
 *
 * \param point
 * \param angle
 */
void RotatePointXY(point_t& point, const double& angle);
/**
 * \brief Rotate points
 *
 * \param points
 * \param points_count
 * \param r_angles
 */
void RotatePoints(point_t* points, const int& points_count, const rotate_t& r_angles);
/**
 * \brief Scale point
 *
 * \param point
 * \param s_coeff
 */
void ScalePoint(point_t& point, const scale_t& s_coeff);
/**
 * \brief Scale points
 *
 * \param points
 * \param points_count
 * \param s_coeff
 */
void ScalePoints(point_t* points, const int& points_count, const scale_t& s_coeff);

#endif // __POINT_FUNCTIONS_AND_TYPES__
