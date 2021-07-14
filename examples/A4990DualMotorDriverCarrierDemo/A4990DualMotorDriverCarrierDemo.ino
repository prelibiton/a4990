#include <A4990DualMotorDriverCarrier.h>
#include <Arduino.h>

/*
 * This example uses the A4990DualMotorDriverCarrier library to drive Motor 2 the
 * Pololu A4990 Dual Motor Driver Carrier. 
 */

#define LED_PIN 13

//**************************************************
// Change this constructor to match your pinout!!!
A4990DualMotorDriverCarrier motors(7, 9, 10, 11);
//**************************************************

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Pololu A4990 Dual Motor Driver Carrier Demo");
  
  // *************************************************
  // Uncomment one or both of the following lines if your motors' directions need to be flipped
  // motors.flipM1(true);
  // motors.flipM2(true);
  // *************************************************
  

  digitalWrite(LED_PIN, HIGH);   // Turn on LED for beautifulness

  //**************************************************
  // Change this constructor to match your pinout!!!
  motors.enableInterrupts(3, 4, 1, 8); // Note that 0, 1 (the interrupt pins) stand for INT0/INT1 and NOT for PD0 or PD1
  //**************************************************

  //motors.setM2Speed(127);
  //motors.stopIfFault();    // It is good practice to stop if there are any errors, stopIfFault() is included for convenience
}

void loop()
{
    for (int speed = 0; speed <= 200; speed++)
  {
    motors.setM1Speed(speed);
    //stopIfFault();
    delay(2);
  }

  for (int speed = 200; speed >= 0; speed--)
  {
    motors.setM1Speed(speed);
    //stopIfFault();
    delay(2);
  }
  
  // run M1 motor with negative speed
  
  digitalWrite(LED_PIN, LOW);
  
  for (int speed = 0; speed >= -200; speed--)
  {
    motors.setM1Speed(speed);
    //stopIfFault();
    delay(2);
  }
  
  for (int speed = -200; speed <= 0; speed++)
  {
    motors.setM1Speed(speed);
    //stopIfFault();
    delay(2);
  }

}
