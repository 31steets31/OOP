#include "paint.h"
#include "model.h"
#include "defines.h"

/**
 * \brief Clear canvas
 *
 * \param canvas
 * \return
 */
void ClearCanvas(canvas_t& canvas)
{
	canvas.canvas->clear();
}