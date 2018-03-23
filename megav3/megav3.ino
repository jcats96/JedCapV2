/*
 Name:		megav3.ino
 Created:	3/22/2018 9:18:18 PM
 Author:	jcats
*/
#include <CapacitiveSensor.h>
#include "capslide.h"

int outputPins[4] = { 3,4,5,6 };
int sendpin = 2;
int recvpins[4] = {22,23,24,25};

int num_samples = 20;
int threshold = 500;

int range = 9000;

CapacitiveSensor SlideOne[4] = {
	CapacitiveSensor(sendpin, recvpins[0]),
	CapacitiveSensor(sendpin, recvpins[1]),
	CapacitiveSensor(sendpin, recvpins[2]),
	CapacitiveSensor(sendpin, recvpins[3]),
};

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(57600);

	Serial.println("hello");

	for (int i = 0; i <4; i++)	pinMode(outputPins[i], OUTPUT);


}

// the loop function runs over and over again until power down or reset
void loop() {
	readSlider(SlideOne, outputPins[0]);
	delay(50);
}
