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
		case TRANSFER_MODEL:
		{
			rc = TransferModel(model, opt.params.t_coord);
			break;
		}
		case ROTATE_MODEL:
		{
			rc = RotateModel(model, opt.params.r_angles);
			break;
		}
		case SCALE_MODEL:
		{
			rc = ScaleModel(model, opt.params.s_coeff);
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
