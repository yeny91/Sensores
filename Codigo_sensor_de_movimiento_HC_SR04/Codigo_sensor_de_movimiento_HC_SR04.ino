//Vcc --> 5V
//Out --> D4
//Gnd --> Gnd
// Adaptado de https://www.luisllamas.es/detector-de-movimiento-con-arduino-y-sensor-pir/



const int LEDPin = 13;        // pin para el LED
const int PIRPin = 2;         // pin de entrada (for PIR sensor)
 
int pirState = LOW;           // de inicio no hay movimiento
int val = 0;                 // estado del pin
 
 void setup() 
{
   pinMode(LEDPin, OUTPUT); 
   pinMode(PIRPin, INPUT);
   Serial.begin(9600);
}
 
void loop()
{
   val = digitalRead(PIRPin);
   if (val == HIGH)   //si está activado
   { 
      digitalWrite(LEDPin, HIGH);  //LED ON
      delay(250);
     Serial.println("Señal activa");
      delay(50);
      
      }
      else 
      {
        digitalWrite(LEDPin, LOW);
        Serial.println("Señal Inactiva");
        delay(50);
        }

        delay(1000); 
   }

   

