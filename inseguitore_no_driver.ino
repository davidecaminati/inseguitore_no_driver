#include <Servo.h>



int val;                  // valore letto in ingresso (range 0-1023)
int pos;                  // posizione del servo
int tolleranza=20;        // isteresi 
int partitore_pin = A0;   // pin di lettura tensione del partitore
int servo_pin = 9;   	  // pin di controllo del servo
Servo myServo;			  // creo l'oggetto servo


void setup()
{
  pinMode(partitore_pin,INPUT);   // imposto il pin del partitore come ingresso per leggere il valore della tensione
  myServo.attach(servo_pin);	  // collego il servo al suo pin di controllo
  Serial.begin(9600);             // attivo la comunicazione seriale 
  pos = 90;                       // imposto il servo in posizione centrale
}

void loop() 
{ 
  val = analogRead(0);            // leggo il valore del partitore (range 0-1023  corrispondente a 0-5 Volt)
  if (val> 512+tolleranza){       // se il partitore legge PIU di 2.5 Volt + la tolleranza
    if (pos < 170){               // se non sono arrivato al MASSIMO del movimento del servo
      pos += 1;                   // INCREMENTO il valore della posizione del servo
      }
    }
  if (val< 512-tolleranza){       // se il partitore legge MENO di 2.5 Volt + la tolleranza
    if (pos > 10){                // se non sono arrivato al MINIMO del movimento del servo
      pos -= 1;                   // RIDUCO il valore della posizione del servo
      }
    }
	myServo.write(pos);			  // comando al servo di andare nella nuova posizione 
    delay (50);                   // attendo 50 millisecondi prima di ripetere il ciclo
} 

