
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void DoorStateMashine(struct DoorStateMashine* inst)
{
	/*TODO: Add your code here*/
	switch(inst->state)
	{
		case ST_INIT:
			if(inst->sw1 == 0 && inst->sw2 == 0 && inst->sw3 == 0 && inst->sw4 == 0)
				inst->state = ST_UNKNOWN;
			break;
		
		case ST_UNKNOWN:
			if(inst->sw1 == 1 && inst->direction == 0)
				inst->state = ST_OPEN;
			if(inst->sw4 == 1 && inst->direction == 1)
				inst->state = ST_CLOSE;
			break;
		
		case ST_OPEN:
			inst->speed = 0;
			if(inst->direction == 0)
				inst->state = ST_ACC_POS;
			break;
		
		case ST_CLOSE:
			inst->speed = 0;
			if(inst->direction == 1)
				inst->state = ST_ACC_NEG;
			break;
		
		case ST_ACC_POS:
			inst->speed = 200;
			if(inst->sw2 == 1)
				inst->state = ST_POS;
			else if(inst->direction == 1)
				inst->state = ST_DEC_NEG;
			break;
		
		case ST_ACC_NEG:
			inst->speed = 0 - 200;
			if(inst->sw3 == 0)
				inst->state = ST_NEG;
			else if(inst->direction == 0)
				inst->state = ST_DEC_POS;
			break;
		
		case ST_POS:
			inst->speed = 400;
			if(inst->sw3 == 1)
				inst->state = ST_DEC_POS;
			else if(inst->direction == 1)
				inst->state = ST_NEG;
			break;
		
		case ST_NEG:
			inst->speed = -400;
			if(inst->sw2 == 0)
				inst->state = ST_DEC_NEG;
			else if(inst->direction == 0)
				inst->state = ST_POS;
			break;
		
		case ST_DEC_POS:
			inst->speed = 200;
			if(inst->sw4 == 1)
				inst->state = ST_CLOSE;
			break;
		
		case ST_DEC_NEG:
			inst->speed = 0 - 200;
			if(inst->sw1 == 0)
				inst->state = ST_OPEN;
			break;
	}
}
