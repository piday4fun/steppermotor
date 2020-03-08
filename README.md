# steppermotor
Stepper motor driver in C for Raspberry Pi.
## How to compile it.
1. Make sure you have wiringPi liberarie.
[Installation Guide](http://www.yoyojacky.com/?p=528)
2. Make sure you connect stepper motor to Raspberry Pi with the right pin.
### GPIO Map
PS : Using Physical Pin number : IN1=11, IN2=12, IN3=13, IN4=15
![GPIO Mapping](imgs/1583592655952.jpg?raw=true)
### Compile it with make command.
```bash
git clone https://github.com/piday4fun/steppermotor.git
cd steppermotor/
make 
```
### Run it in command line.
#### Clockwise 
```bash
./stepper 0 
```
#### Counter-Clockwise
```bash
./stepper 1
```
### Have fun!
