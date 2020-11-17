
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
void LedStateMashine(struct LedStateMashine* inst)
{
	/*TODO: Add your code here*/
	inst->timer++;
	switch(inst->state)
	{
		case ST_INIT:
			break;
		
		case ST_UNKNOWN:
			if(inst->timer % 10 == 0)
			{
				inst->led1 = !inst->led1;
				inst->led2 = !inst->led2;
				inst->led3 = !inst->led3;
				inst->led4 = !inst->led4;
			}
			break;
		
		case ST_OPEN:
			inst->led1 = 0;
			inst->led2 = 0;
			inst->led3 = 0;
			inst->led4 = 0;
			break;
		
		case ST_CLOSE:
			inst->led1 = 1;
			inst->led2 = 1;
			inst->led3 = 1;
			inst->led4 = 1;
			break;
		
		case ST_ACC_POS:
			inst->led1 = 1;						
			if(inst->timer % 10 == 0)
				inst->led2 = !inst->led2;
			inst->led3 = 0;
			inst->led4 = 0;
			break;
		
		case ST_ACC_NEG:
			inst->led1 = 1;
			inst->led2 = 1;			
			if(inst->timer % 10 == 0)
				inst->led3 = !inst->led3;
			inst->led4 = 0;
			break;
		
		case ST_POS:
			inst->led1 = 1;			
			inst->led2 = 1;			
			if(inst->timer % 10 == 0)
				inst->led3 = !inst->led3;
			inst->led4 = 0;
			break;
		
		case ST_NEG:
			inst->led1 = 1;						
			if(inst->timer % 10 == 0)
				inst->led2 = !inst->led2;
			inst->led3 = 0;
			inst->led4 = 0;
			break;
		
		case ST_DEC_POS:
			inst->led1 = 1;
			inst->led2 = 1;			
			if(inst->timer % 10 == 0)
				inst->led3 = !inst->led3;
			inst->led4 = 0;
			break;
		
		case ST_DEC_NEG:		
			if(inst->timer % 10 == 0)
				inst->led1 = !inst->led1;
			inst->led2 = 0;
			inst->led3 = 0;
			inst->led4 = 0;
			break;
	}
}
