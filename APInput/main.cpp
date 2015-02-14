#include<iostream>
#include"APInput.h"
#include<string>

using namespace std;

APInput ap[4] = {1, 2, 3, 4};

int main() {
	while(true) {
		for(int i = 0; i < 4; i++) {
			ap[i].updateController();
			cout<<"Controller "<<ap[i].getControllerNumber()<<" Connected: "<<(ap[i].isControllerConnected() == 1 ? "TRUE" : "FALSE")<<"\r\n";
			
			cout<<"Left Thumbstick - X: "<<ap[i].leftThumbstickX()<<"  Y: "<<ap[i].leftThumbstickY()<<"\r\n";
			cout<<"Right Thumbstick - X: "<<ap[i].rightThumbstickX()<<"  Y: "<<ap[i].rightThumbstickY()<<"\r\n";
			cout<<"Back Triggers - Left: "<<ap[i].leftTrigger()<<"  Right: "<<ap[i].rightTrigger()<<"\r\n";
			
			if(ap[i].isButtonPressed(ap[i].BACK)) {
				cout<<"BACK\r\n";
			}
			if(ap[i].isButtonPressed(ap[i].START)) {
				cout<<"START\r\n";
			}
			if(ap[i].isButtonPressed(ap[i].LEFT_SHOULDER)) {
				cout<<"LEFT_SHOULDER\r\n";
			}
			if(ap[i].isButtonPressed(ap[i].RIGHT_SHOULDER)) {
				cout<<"RIGHT_SHOULDER\r\n";
			}
			if(ap[i].isButtonPressed(ap[i].A)) {
				cout<<"A\r\n";
			}
			if(ap[i].isButtonPressed(ap[i].B)) {
				cout<<"B\r\n";
			}
			if(ap[i].isButtonPressed(ap[i].X)) {
				cout<<"X\r\n";
			}
			if(ap[i].isButtonPressed(ap[i].Y)) {
				cout<<"Y\r\n";
			}
			if(ap[i].isButtonPressed(ap[i].DPAD_UP)) {
				cout<<"DPAD_UP\r\n";
			}
			if(ap[i].isButtonPressed(ap[i].DPAD_DOWN)) {
				cout<<"DPAD_DOWN\r\n";
			}
			if(ap[i].isButtonPressed(ap[i].DPAD_LEFT)) {
				cout<<"DPAD_LEFT\r\n";
			}
			if(ap[i].isButtonPressed(ap[i].DPAD_RIGHT)) {
				cout<<"DPAD_RIGHT\r\n";
			}
			if(ap[i].isButtonPressed(ap[i].LEFT_THUMBSTICK)) {
				cout<<"LEFT_THUMBSTICK\r\n";
			}
			if(ap[i].isButtonPressed(ap[i].RIGHT_THUMBSTICK)) {
				cout<<"RIGHT_THUMBSTICK\r\n";
			}

			ap[i].setVibration(ap[i].leftTrigger(), ap[i].rightTrigger());

			cout<<"\r\n\r\n";
		}
		
		cout<<"Thumbstick Dead Zones - Left: "<<ap[0].leftThumbstickDeadZone()<<"  Right: "<<ap[0].rightThumbstickDeadZone()<<"\r\n";

		Sleep(100);
		system("cls");
	}

	return 0;
}