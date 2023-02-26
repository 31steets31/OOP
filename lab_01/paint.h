#ifndef __PAINT__
#define __PAINT__

#include <QGraphicsScene>

typedef struct
{
	QGraphicsScene *canvas;
} canvas_t;

/**
 * \brief Clear canvas
 *
 * \param canvas
 * \return
 */
void ClearCanvas(canvas_t& canvas);

#endif // __PAINT__
