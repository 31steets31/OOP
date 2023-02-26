#ifndef __TASK_MANAGER__
#define __TASK_MANAGER__

enum actions
{
	LOAD_MODEL,
	DESTROY_MODEL,
};

typedef struct
{
	actions action;
	union
	{
		const char *filename;
	} params;
} options_t;

/**
 * \brief Process command
 *
 * \param opt
 * \return 
 */
errors Process(options_t& opt);

#endif // !__TASK_MANAGER__


