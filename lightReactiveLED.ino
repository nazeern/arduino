int lightPin=A0;
int ledPin=9;
float lightVal;
int pwr;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPin,INPUT);
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  pwr = (50./1023.) * lightVal - 9;
  analogWrite(ledPin,pwr);
}
