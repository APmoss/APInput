#include<Windows.h>
#include<Xinput.h>

#pragma comment(lib, "XInput.lib")

class APInput {
private:
	int controller;
	XINPUT_STATE state;
public:
	static enum Button {
		BACK,
		START,
		LEFT_SHOULDER,
		RIGHT_SHOULDER,
		A, B, X, Y,
		DPAD_UP,
		DPAD_DOWN,
		DPAD_LEFT,
		DPAD_RIGHT,
		LEFT_THUMBSTICK,
		RIGHT_THUMBSTICK
	};

	APInput(int);

	void updateController();
	bool isControllerConnected();
	int getControllerNumber();
	double leftThumbstickDeadZone();
	double rightThumbstickDeadZone();
	double triggerThreshold();
	bool isButtonPressed(Button);
	double leftThumbstickX();
	double leftThumbstickY();
	double rightThumbstickX();
	double rightThumbstickY();
	double leftTrigger();
	double rightTrigger();

	void setVibration(double, double);
};