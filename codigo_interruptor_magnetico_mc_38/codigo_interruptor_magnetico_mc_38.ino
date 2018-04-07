// ######################################
// # Sensor al Digital 3 y a GND
// # Interruptor D3 Interrupcion 1
// # http://arubia45.blogspot.com.es
// ######################################


// Definiciones
boolean abierto = false;
int cambios;

// Rutina de Interrupción
void interrupcion()
{
  abierto = true;
//  Serial.print("cambio ");
  if (cambios == 0)
    cambios ++;
  else {
    cambios = 0;
    abierto = false;
  }
  //Serial.println(cambios);
}

void setup() {
  Serial.begin(9600);
  // Interruptor D3 Interrupcion 1
  digitalWrite(3, HIGH);
  attachInterrupt(1,interrupcion,HIGH); // Attaching the ISR to INT0 
}

void loop() {
  delay (1000);
  if (abierto)
    Serial.println("Abierto");
  else
    Serial.println("Cerrado");
}

