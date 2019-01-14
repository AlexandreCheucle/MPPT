
#define LED_1  13
#define LED_2  8
#define frequence 100

void setup()
{
	pinMode(LED_1, OUTPUT);
	pinMode(LED_2, OUTPUT);
}

void loop()
{
	digitalWrite(LED_1, HIGH);
	delay(frequence);
	digitalWrite(LED_1, LOW);
	digitalWrite(LED_2, HIGH);
	delay(frequence);
	digitalWrite(LED_2, LOW);

}

