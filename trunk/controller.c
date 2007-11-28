
#include <pspctrl.h>
#ifdef __cplusplus
extern "C" {
#endif
SceCtrlData pad;
void SetupController()
{
	sceCtrlSetSamplingCycle(0);
	sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);
}
unsigned char GetJoystickX(void)
{
	sceCtrlReadBufferPositive(&pad, 1);
	return pad.Lx;
}
unsigned char GetJoystickY(void)
{
	sceCtrlReadBufferPositive(&pad, 1);
	return pad.Ly;
}
unsigned int GetButtonsPressed(void)
{
	sceCtrlReadBufferPositive(&pad, 1);
	return pad.Buttons;
}
#ifdef __cplusplus
}
#endif

