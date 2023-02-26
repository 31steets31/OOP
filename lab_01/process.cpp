#include "model.h"
#include "errors.h"
#include "process.h"
#include "in_out.h"

/**
 * \brief Process command
 * 
 * \param opt
 * \return 
 */
errors Process(options_t &opt)
{
	static model_t &model = InitModel();

	errors rc = ERR_SUCCESS;

	switch (opt.action)
	{
		case LOAD_MODEL:
		{
			rc = LoadModel(model, opt.params.filename);
			break;
		}
		case DRAW_MODEL:
		{
			rc = DrawModel(model, opt.params.canvas);
			break;
		}
		case DESTROY_MODEL:
		{
			FreeModel(model);
			break;
		}
		default:
		{
			rc = ERR_INCORRECT_COMMAND;
			break;
		}
	}

	return rc;
}
