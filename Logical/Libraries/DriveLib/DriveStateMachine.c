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
	UINT state = inst->state & 0x6F;
	if(inst->enable == 0)
		inst->command = CMD_SHUTDOWN;
	else
		switch(state)
		{
			case STATE_DISABLED:
				inst->command = CMD_SHUTDOWN;
				break;
			
			case STATE_SWITCHED_ON:
				inst->command = CMD_SWITCH_ON;
				break;
			
			case STATE_READY:
				inst->command = CMD_ENABLE;
				break;				
		}
}
