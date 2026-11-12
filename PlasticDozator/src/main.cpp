#include <Arduino.h>
#include <CheapStepper.h>

CheapStepper stepper (8,9,10,11); 
boolean moveClockwise = true;

#define DRIVER_PIN1 11 
#define DRIVER_PIN2 10 
#define DRIVER_PIN3 9 
#define DRIVER_PIN4 8 
void setup()
{
  stepper.setRpm(20); 
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  Serial.begin(115200);
}
void loop()
{
  digitalWrite(A4, LOW);
  digitalWrite(A3, HIGH);
  int val = analogRead(A2);
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

  stepper.moveToDegree (moveClockwise, 90);
  delay(8000);
  stepper.moveToDegree (moveClockwise, 180);
  delay(8000);


}


