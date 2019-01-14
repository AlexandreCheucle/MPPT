const int sensorPin0 = A0;
const int sensorPin1 = A1;
const int Val_res = 20;
const int controlpin = 2;

void setup()
{
	Serial.begin(9600);	
	pinMode(controlpin, OUTPUT);
}

void loop()
{

	digitalWrite(controlpin, HIGH);

  int sensorVal0 = analogRead(sensorPin0);
  int sensorVal1 = analogRead(sensorPin1);

  float Val0 = (sensorVal0 / 1024.0) * 5.0;
  float Val1 = ((sensorVal1)/1024.0)*5.0;
  
  
  Serial.print("V0 = ");
	Serial.print(Val0);
	Serial.print("V ");
	Serial.print(sensorVal0);
	Serial.print("\n");

	Serial.print("V1 = ");
	Serial.print(Val1);
	Serial.print("V ");
	Serial.print(sensorVal1);
	Serial.print("\n");
  

  Serial.print("I0 = ");
  Serial.print((Val1-Val0/Val_res) * 1000);
  Serial.print("mA");
  Serial.print("\n");
  
  delay(1000);
}
