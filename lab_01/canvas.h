#ifndef __CANVAS__
#define __CANVAS__

#include <QGraphicsScene>

/**
 * \brief Canvas
 */
struct canvas_t
{
	QGraphicsScene* canvas;
};

/**
 * \brief Clear canvas
 *
 * \param canvas
 * \return
 */
void ClearCanvas(canvas_t& canvas);

#endif // __CANVAS__
