const int sensorPin1 = A0;
const int sensorPin2 = A1;
void setup()
{
	Serial.begin(9600);	
}

void loop()
{
	int sensorVal = analogRead(sensorPin1);
	float voltage = (sensorVal / 1024.0) * 5.0;
	Serial.print(voltage);
	Serial.print("\n");
}
