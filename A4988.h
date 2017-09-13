#ifndef A4988_h
#define A4988_h

class A4988 {
	public:
		A4988(int stepsPerRev, int stpPin, int dirPin);
		
		void setStepperSpeed(int speed); 
		void stepStepper(int steps); 
		
	private: 
		int stpPin;
		int dirPin; 
		int rpm; 
		int delayTime;
		int stepsPerRev; 
	
	
	
	






};

#endif