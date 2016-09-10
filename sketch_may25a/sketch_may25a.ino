#include <Stepper.h>


const int ForwardLimitSwitchPin = 2;
const int ReverseLimitSwitchPin = 3;
const int StepperStepPin = 4;
const int StepperDirectionPin = 5;
const int LimitSwitchActivated = LOW;  // Limit switch grounds pin
const int StepperMaxRPM = 100;

Stepper stepper(200, StepperStepPin, StepperDirectionPin);

void setup() {
   pinMode(ForwardLimitSwitchPin, INPUT_PULLUP);
   pinMode(ReverseLimitSwitchPin, INPUT_PULLUP);
   stepper.setSpeed(StepperMaxRPM);
}

void loop() {
   // Step forward until the limit switch is activated
   while (digitalRead(ForwardLimitSwitchPin) != LimitSwitchActivated) {
       stepper.step(1);
   }
   // Step reverse until the limit switch is activated
   while (digitalRead(ReverseLimitSwitchPin) != LimitSwitchActivated) {
       stepper.step(-1);
   }
}
