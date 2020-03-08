#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int CLOCKWISE_PINS[4] = {0, 1, 2, 3};
int COUNTER_CLOCKWISE_PINS[4] = {3, 2, 1, 0};

void delayMS(int x) {
	usleep(x * 1000);
}	

void rotate(int* pins, int reverse) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			int k = reverse ? 3 - j : j;

			digitalWrite(pins[k], (j == i) ? 1 : 0); 
		}

		delayMS(2);
	}
}

int init_port() {
	int ret =  wiringPiSetup();

	if(-1 != ret) {
		for(int p = 0; p < 4; p++) {
			pinMode(p, OUTPUT);
		}
	
		delayMS(50);
	}

	return ret;
}

int main(int argc,char* argv[]) {
	if(argc < 2) {
		printf("Usage example: ./stepper 0 \n");
		return 1;
	}

	int direction = atoi(argv[1]);
	int* pins = direction ? CLOCKWISE_PINS : COUNTER_CLOCKWISE_PINS;

	if(-1 == init_port()) {
		printf("Setup wiringPi failed!\n");
		return 1;
	}

	for(int i = 0; i < 500; i++) {
		rotate(pins, 0);
	}
	
	return 0;
}

