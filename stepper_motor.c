#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define CLOCKWISE 1 
#define COUNTER_CLOCKWISE 2

void delayMS(int x);
void rotate(int* pins, int direction);

int main(int argc,char* argv[]){
	if(argc < 4){
		printf("Usage example: ./stepper 0 1 2 3 \n");
		return 1;
		}
	int IN1 = atoi(argv[1]);
	int IN2 = atoi(argv[2]);
	int IN3 = atoi(argv[3]);
	int IN4 = atoi(argv[4]);

	int pins[4] = {IN1, IN2, IN3, IN4};

	if(-1 == wiringPiSetup()){
		printf("Setup wiringPi failed!\n");
		return 1;
	}

	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);

	delayMS(50);
	for(int i=0; i<500; i++){
		rotate(pins, CLOCKWISE);
		}
	return 0;
	}

void delayMS(int x){
	usleep(x * 1000);
	}	

void rotate(int* pins, int direction){
	for(int i=0;i<4;i++){
		if(CLOCKWISE == direction){
			for(int j=0;j<4;j++){
				if(j==i){
					digitalWrite(pins[3-j],1);
					}
				else{
					digitalWrite(pins[3-j],0);
					}
			} 
		}else if(COUNTER_CLOCKWISE == direction){
				for(int j=0; j<4;j++){
				if(j==i){
					digitalWrite(pins[j],1);
				}
				else{
					digitalWrite(pins[j],0);
				}
			}
		     }
	delayMS(4);
		}
	}
