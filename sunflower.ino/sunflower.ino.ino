/*  0932 - Simple servo motor demo
 * 
 * This sketch shows you how to control two small 5V servo motors connected directly to the Arduino.
 * 
 * The sketch makes the arm of the servo motor to move in a 180 degree angle.
 */

#include <Servo.h> 
 
Servo myservo;
 
int servoPin = 9;
int lightPin = A0;
int lightRaw;
int servLo = 30;
int servHi = 110;
int lightLo = 160;
int lightHi = 730;
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  pinMode(servoPin,OUTPUT);
  pinMode(lightPin,INPUT);
  Serial.begin(9600);
} 
 
 
void loop() 
{ 
  lightRaw = analogRead(lightPin);

  Serial.print("Raw Light Reading: ");
  Serial.println(lightRaw);
  pos = lightRawToServ(lightRaw);

  Serial.print("Servo Output: ");
  Serial.println(pos);
  Serial.println();

  myservo.write(pos);
} 


float lightRawToServ(int lightRaw)
{
  float m = (float)(servHi - servLo) / (float)(lightHi - lightLo);
  float b = servLo - m * lightLo;
  return m * lightRaw + b;
}
