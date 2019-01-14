const int sensorPin1 = A0;
const int sensorPin2 = A1;
void setup()
{
	Serial.begin(9600);	
}

void loop()
{
	int sensorVal1 = analogRead(sensorPin1);
  int sensorVal2 = analogRead(sensorPin2);
  float current = ((sensorVal2-sensorVal1)/1024.0)*5.0;
	float voltage = (sensorVal1 / 1024.0) * 5.0;
  Serial.print("V = ");
	Serial.print(voltage);
	Serial.print("\n");
  Serial.print("I = ");
  Serial.print(current);
  Serial.print("\n");
  delay(100);
}
