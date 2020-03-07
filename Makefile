# Makefile V1.0
# Editor: yoyojacky
stepper:stepper_motor.o
	gcc -o stepper -lwiringPi stepper_motor.o
stepper.o:stepper_motor.c
	gcc -c stepper_motor.c
.PHONY:clean
clean: 
	rm stepper_motor.o stepper
	echo "Repository is clean"
