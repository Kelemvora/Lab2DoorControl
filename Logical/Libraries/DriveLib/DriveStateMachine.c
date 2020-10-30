
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif
void DriveStateMachine(struct DriveStateMachine* inst)
{
	/*TODO: Add your code here*/
	UINT state = inst->state & 0x6f;
	switch(state)
	{
		case STATE_DISABLED:
			if(inst->enable == 0)
				inst->command = CMD_SHUTDOWN;
			else
				inst->command = CMD_SWITCH_ON;
			break;
		
		case STATE_SWITCHED_ON:
			if(inst->enable == 0)
				inst->command = CMD_SHUTDOWN;
			else
				inst->command = CMD_ENABLE;
			break;
		
		case STATE_READY:
			if(inst->enable == 0)
				inst->command = CMD_SHUTDOWN;
			break;				
	}
}
