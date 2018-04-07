//##########################################
//# Pin Vcc a 5v
//# pin Out a A0
//# Pin Gnd a Gnd 
// codigo adapatado de: http://www.naylampmechatronics.com/blog/48_tutorial-sensor-de-corriente-acs712.html


float Sensibilidad=0.66; //sensibilidad en V/A para nuestro sensor
float offset=0; // Equivale a la amplitud del ruido
void setup() {
  
  Serial.begin(9600);
}

void loop() {

 


// para corriente ac
  float Ip=get_corriente1();//obtenemos la corriente pico
  float Irms=Ip*0.707; //Intensidad RMS = Ipico/(2^1/2)
  float P=Irms*110.0; // P=IV watts



 //corriente dc 
 float I=get_corriente(200);//obtenemos la corriente promedio de 500 muestras 
  
 Serial.print("Ip: ");
  Serial.print(Ip,3);
  Serial.print("A , Irms: ");
  Serial.print(Irms,3);
  Serial.print("A, Potencia: ");
  Serial.print(P,3);  
  Serial.print("W, corriente "); 
  Serial.print(I,3); 
   Serial.println("A "); 
  delay(100);  

delay(500); 

  
   }  
    
    

 
  
   


float get_corriente1()
{
  float voltajeSensor;
  float corriente=0;
  long tiempo=millis();
  float Imax=0;
  float Imin=0;
  while(millis()-tiempo<500)//realizamos mediciones durante 0.5 segundos
  { 
    voltajeSensor = analogRead(A0) * (5.0 / 1023.0);//lectura del sensor
    corriente=0.9*corriente+0.1*((voltajeSensor-2.5)/Sensibilidad); //Ecuación  para obtener la corriente
    if(corriente>Imax)Imax=corriente;
    if(corriente<Imin)Imin=corriente;
  }
  return(((Imax-Imin)/2)-offset);
}



float get_corriente(int n_muestras)
{
  float voltajeSensor;
  float corriente=0;
  for(int i=0;i<n_muestras;i++)
  {
    voltajeSensor = analogRead(A0) * (5.0 / 1023.0);////lectura del sensor
    corriente=corriente+(voltajeSensor-2.5)/Sensibilidad; //Ecuación  para obtener la corriente
  }
  corriente=corriente/n_muestras;
  return(corriente);
}


