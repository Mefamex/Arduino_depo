#include <X113647Stepper.h>
const int hiz = 32*1;
X113647Stepper myStepper(hiz, 8, 9, 10, 11);
void setup()
{
  myStepper.setSpeed(10000000);
	pinMode(A0,INPUT);		
}
void loop()
{
			if(analogRead(A0)<500){	
myStepper.step(hiz);
				}
			if(analogRead(A0)>500){	
	myStepper.step(-hiz);
				}
				
				}