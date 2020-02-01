
/*  3257's EPIC MOTOR TESTING BOX
 *  Programming, Mechanical Assembly and Wiring by the Electrical Team
 *  -----------------------------
 *  uncomment the commented lines of code for serial debugging.
 * 
 * Tested to work with Spark motor controllers, but should theoretically work
 * with any PWM based motor controller.
 */
#include <Servo.h> //this servo library is required for sending PWM to the motor controller
Servo myservo;
int sensorPin = A7; //Signal wire of the potentiometer at Analog Pin 7
int value = 0; 
void setup() {
//Serial.begin(9600); 
pinMode(2, INPUT_PULLUP);//sets up digital pin 2 for use as button input and sets internal resistor
myservo.writeMicroseconds(1500); //starts off as neutral
myservo.attach(3); //PWM signal wire at Digital Pin 3

}
void loop() {

value = analogRead(A7); 
value = map(value, 0, 725, 1000, 2000);

delay(50);

if (digitalRead(2) == LOW) { //if button is pressed, send signal
//Serial.println("LOW");
 myservo.writeMicroseconds(value);
}

else if(digitalRead(2) == HIGH) { //if button is not pressed, don't send signal
  myservo.writeMicroseconds(1500);//sets to neutral instead
}

//Serial.println(value);


}
