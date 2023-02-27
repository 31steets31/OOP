#ifndef __POINT_FUNCTIONS_AND_TYPES__
#define __POINT_FUNCTIONS_AND_TYPES__

#include "process.h"

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
 * \brief Transfer point
 *
 * \param point
 * \param t_coord
 */
void TransferPoint(point_t& point, const transfer_t& t_coord);
/**
 * \brief Scale point
 *
 * \param point
 * \param s_coeff
 */
void ScalePoint(point_t& point, const scale_t& s_coeff);
/**
 * \brief Rotate point around Oy and Oz
 *
 * \param point
 * \param r_angles
 */
void RotatePointYZ(point_t& point, const rotate_t& r_angles);
/**
 * \brief Rotate point around Ox and Oz
 *
 * \param point
 * \param r_angles
 */
void RotatePointXZ(point_t& point, const rotate_t& r_angles);
/**
 * \brief Rotate point around Ox and Oy
 *
 * \param point
 * \param r_angles
 */
void RotatePointXY(point_t& point, const rotate_t& r_angles);

#endif // __POINT_FUNCTIONS_AND_TYPES__
