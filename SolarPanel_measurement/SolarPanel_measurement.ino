const int sensorPin0 = A0;
const int sensorPin1 = A1;
const int sensorPin2 = A2;
const int sensorPin3 = A3;
const int Val_res = 20;
const int controlpin = 3;
 int alpha = 0;

const int gain = 1000;
const int val_res = 1;

int pin1Moteur1=6; //pin de commande moteur 1
int pin2Moteur1=7; // pin de commande moteur 1
int pinPMoteur1=5;// pin PWM moteur 1

float Val0;
float Val1;
float Val2;
float Val3;

float Ipanel;
float power_old = 0;
float power = 0;

void setup()
{
	Serial.begin(9600);	
	pinMode(controlpin, OUTPUT);

	pinMode(pin1Moteur1,OUTPUT);
  	pinMode(pin2Moteur1,OUTPUT);
	pinMode(pinPMoteur1,OUTPUT);

}

void loop()
{

	Serial.print("Alpha :");
	Serial.print(alpha);
	Serial.print("\n");

	analogWrite(controlpin, alpha);

	mesure_IV();
	  
	  
	 power = Ipanel * Val0;

	
	 MPPT_search();

	actionMoteur(0,100);
  

  /*Serial.print("I0 = ");
  Serial.print((Val1-Val0/Val_res) * 1000);
  Serial.print("mA");
  Serial.print("\n");*/
  
  delay(1000);
}


void actionMoteur(int sens,int pourcentage){ // inspiré du code OC : https://openclassrooms.com/fr/courses/2778161-programmez-vos-premiers-montages-avec-arduino/3285355-le-moteur-a-courant-continu-partie-2-le-pont-en-h-et-les-circuits-integres

  int pin1,etat1,pin2,etat2,pinP,puissance; //variable de la fonction

    pin1=pin1Moteur1;
    pin2=pin2Moteur1;
    pinP=pinPMoteur1;

  //test sens du moteur 1,-1 (sens contrainre) ou tout autre valeur (stoppe le moteur)

  if (sens==1){
    etat1=1;
    etat2=0;
  }
  else if (sens==-1){
    etat1=0;
    etat2=1;
  }
  else {
    etat1=0;
    etat2=0;
  }

  puissance=map(pourcentage,0,100,0,255);

  analogWrite(pinP,puissance);
  digitalWrite(pin1,etat1);
  digitalWrite(pin2,etat2);

  //affichage sur le moniteur série (facultatif)
  

  if (sens==-1 || sens==1){
    Serial.print(" sens : ");
    Serial.print(sens);
  }

  else {
    Serial.print(" ! stop ! ");
  }
  Serial.print(" puissance : ");
  Serial.println(pourcentage);
}

void mesure_IV() {

	int sensorVal0 = analogRead(sensorPin0);
	int sensorVal1 = analogRead(sensorPin1);
	int sensorVal2 = analogRead(sensorPin2); //Vout ampli-op
	int sensorVal3 = analogRead(sensorPin3); // Vin- ampli op

	Val0 = (sensorVal0 / 1024.0) * 5.0;
	Val1 = ((sensorVal1)/1024.0)*5.0;
	Val2 = ((sensorVal2)/1024.0)*5.0;
	Val3 = ((sensorVal3)/1024.0)*5.0;


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

	Serial.print("Vout = ");
	Serial.print(Val2);
	Serial.print("V ");
	Serial.print(sensorVal2);
	Serial.print("\n");

	Ipanel = Val2/(gain*val_res) * 1000;
	
	Serial.print("Ipanel = ");
	Serial.print(Ipanel);
	Serial.print("mA ");
	Serial.print("\n");
}

void MPPT_search() {
	Serial.print("Ppanel = ");
	Serial.print(power);
	Serial.print("mW ");
	Serial.print("\n");

	if (power_old > power) {
		alpha--;
	}
	else {
		alpha ++;
	}
	power_old = power;
}