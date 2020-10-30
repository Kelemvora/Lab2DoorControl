
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	Drive.enable = 1;
}

void _CYCLIC ProgramCyclic(void)
{
	DoorStateMashine(&Door);
	Drive.speed = Door.speed;
	DriveStateMachine(&Drive);
	Led.state = Door.state;
	LedStateMashine(&Led);
}

void _EXIT ProgramExit(void)
{
	
}

