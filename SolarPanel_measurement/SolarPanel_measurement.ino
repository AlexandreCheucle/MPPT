const int sensorPin = A0;

void setup()
{
	Serial.begin(9600);	
}

void loop()
{
	int sensorVal = analogRead(sensorPin);
	float voltage = (sensorVal / 1024.0) * 5.0;
	Serial.print(voltage);
	Serial.print("\n");
}

