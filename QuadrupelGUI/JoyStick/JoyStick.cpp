// JoyStick.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include <Windows.h>
#include <MMSystem.h>

JOYINFO joystickInfo;

JOYINFOEX joystick;

HANDLE hserial;
DCB dcbSerialParams = { 0 };

extern "C" __declspec(dllexport) int* ReadJoystick();

extern "C" __declspec(dllexport) int* ReadJoystick()
{
	int * arr = new int[6];

	arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = arr[5] = 0;

	bool joystickfound = false;

	UINT joystickId = JOYSTICKID1;
	ZeroMemory(&joystick, sizeof(joystick));
	joystick.dwSize = sizeof(joystick);
	joystick.dwFlags = JOY_RETURNALL;

	MMRESULT errorCode = joyGetPosEx(joystickId, &joystick);

	switch (errorCode)
	{
	case JOYERR_NOERROR:     joystickfound = true;
	{
		
		arr[0] = joystick.dwXpos;
		arr[1] = joystick.dwYpos;
		arr[2] = joystick.dwRpos;
		arr[3] = joystick.dwZpos;
		if (joystick.dwButtons & 0x1)
		{
			arr[4] = 1; //-> Panic button

		}
		arr[5] = 1;
		break;
	}

	default:joystickfound = false;
		arr[0] = 32767;
		arr[1] = 32767;
		arr[2] = 32767;
		arr[3] = 32767;
		arr[4] = 0;
		arr[5] = 0;
		break;
	}
	return arr;
}
//Arun Geo Thomas
extern "C" __declspec(dllexport) void array_release(int* ptr)
{
	delete[] ptr;
}

extern "C" __declspec(dllexport) int* ReadFPGA()
{
	int * arr = new int[5];
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 30;
	arr[3] = 4;
	arr[4] = 5;
	return arr;
}
