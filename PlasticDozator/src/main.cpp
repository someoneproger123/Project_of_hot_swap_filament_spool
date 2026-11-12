#include <Arduino.h>
#include <CheapStepper.h>

#define DRIVER1_PIN1 11 
#define DRIVER1_PIN2 10 
#define DRIVER1_PIN3 9 
#define DRIVER1_PIN4 8 
#define DRIVER2_PIN1 7 
#define DRIVER2_PIN2 6 
#define DRIVER2_PIN3 5 
#define DRIVER2_PIN4 4
#define FILAMENT_SENSOR1 12
#define FILAMENT_SENSOR2 3
#define SPEED_SENSOR2 A2
#define SPEED_SENSOR1 A1


CheapStepper stepper (DRIVER1_PIN4,DRIVER1_PIN3,DRIVER1_PIN2,DRIVER1_PIN1); 
boolean moveClockwise = true;

void setup()
{
  stepper.setRpm(20); 
  pinMode(SPEED_SENSOR1, INPUT);
  Serial.begin(115200);
}
void loop()
{
  int val = analogRead(SPEED_SENSOR1);
  int len = map(val, 0, 1024, 0, 6);


  delay(1000);
  Serial.print("Len = ");
  Serial.println(len);
  Serial.print("Val = ");
  Serial.println(val);

  stepper.setRpm(10);
  Serial.print(stepper.getRpm()); // get the RPM of the stepper
  Serial.print(" rpm = delay of ");
  Serial.print(stepper.getDelay()); // get delay between steps for set RPM
  Serial.print(" microseconds between steps");
  Serial.println();

  // stepper.move (moveClockwise, 4096);
  // delay(8000);
  // stepper.move (moveClockwise, 4096);
  // delay(8000);

  
}


