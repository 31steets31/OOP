#ifndef __PROCESS__
#define __PROCESS__

#include "paint.h"
#include "defines.h"

enum actions
{
	LOAD_MODEL,
	DESTROY_MODEL,
	DRAW_MODEL,
};

typedef struct
{
	actions action;
	union
	{
		char filename[MAX_FILENAME_LEN + 1];
		canvas_t canvas;
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


