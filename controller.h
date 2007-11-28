#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_
#ifdef __cplusplus
extern "C" {
#endif


void SetupController();

unsigned char GetJoystickX(void);

unsigned char GetJoystickY(void);

unsigned int GetButtonsPressed(void);


#ifdef __cplusplus
}
#endif


#endif
