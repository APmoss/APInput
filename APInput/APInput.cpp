#include"APInput.h"

APInput::APInput(int controllerNumber) {
	controller = controllerNumber - 1;
}

void APInput::updateController() {
	ZeroMemory(&state, sizeof(XINPUT_STATE));

	XInputGetState(controller, &state);
}

bool APInput::isControllerConnected() {
	ZeroMemory(&state, sizeof(XINPUT_STATE));

	DWORD result = XInputGetState(controller, &state);

	return result == ERROR_SUCCESS;
}

int APInput::getControllerNumber() {
	return controller + 1;
}

double APInput::leftThumbstickDeadZone() {
	return (double)XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE / 32767;
}
double APInput::rightThumbstickDeadZone() {
	return (double)XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE / 32767;
}
double APInput::triggerThreshold() {
	return (double)XINPUT_GAMEPAD_TRIGGER_THRESHOLD / 255;
}

bool APInput::isButtonPressed(Button button) {
	switch(button) {
	case BACK:
		return state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK;
		break;
	case START:
		return state.Gamepad.wButtons & XINPUT_GAMEPAD_START;
		break;
	case LEFT_SHOULDER:
		return state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER;
		break;
	case RIGHT_SHOULDER:
		return state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER;
		break;
	case A:
		return state.Gamepad.wButtons & XINPUT_GAMEPAD_A;
		break;
	case B:
		return state.Gamepad.wButtons & XINPUT_GAMEPAD_B;
		break;
	case X:
		return state.Gamepad.wButtons & XINPUT_GAMEPAD_X;
		break;
	case Y:
		return state.Gamepad.wButtons & XINPUT_GAMEPAD_Y;
		break;
	case DPAD_UP:
		return state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP;
		break;
	case DPAD_DOWN:
		return state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN;
		break;
	case DPAD_LEFT:
		return state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT;
		break;
	case DPAD_RIGHT:
		return state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT;
		break;
	case LEFT_THUMBSTICK:
		return state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB;
		break;
	case RIGHT_THUMBSTICK:
		return state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB;
		break;
	default:
		return false;
	}
}

double APInput::leftThumbstickX() {
	return ((double)(state.Gamepad.sThumbLX + 32768) / 65535 - .5) * 2;
}
double APInput::leftThumbstickY() {
	return ((double)(state.Gamepad.sThumbLY + 32768) / 65535 - .5) * 2;
}
double APInput::rightThumbstickX() {
	return ((double)(state.Gamepad.sThumbRX + 32768) / 65535 - .5) * 2;
}
double APInput::rightThumbstickY() {
	return ((double)(state.Gamepad.sThumbRY + 32768) / 65535 - .5) * 2;
}

double APInput::leftTrigger() {
	return (double)state.Gamepad.bLeftTrigger / 255;
}
double APInput::rightTrigger() {
	return (double)state.Gamepad.bRightTrigger / 255;
}

void APInput::setVibration(double leftMotor, double rightMotor) {
	XINPUT_VIBRATION vibration;

	ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));
	
	vibration.wLeftMotorSpeed = (int)(leftMotor * 65535);
	vibration.wRightMotorSpeed = (int)(rightMotor * 65535);

	XInputSetState(controller, &vibration);
}