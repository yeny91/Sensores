// Pin rojo--> 5v
// Pin amarillo--> D2
// Pin negro --> Gnd
// Codigo adaptado de  http://www.naylampmechatronics.com/blog/47_tutorial-sensor-de-flujo-de-agua.html    


volatile int NumPulsos; //variable para la cantidad de pulsos recibidos
int PinSensor = 2;    //Sensor conectado en el pin 2
float factor_conversion=7.5; //para convertir de frecuencia a caudal

//---Función que se ejecuta en interrupción---------------
void ContarPulsos ()
{ 
  NumPulsos++;  //incrementamos la variable de pulsos
} 

//---Función para obtener frecuencia de los pulsos--------
int ObtenerFrecuencia() 
{
  int frecuencia;
  NumPulsos = 0;   //Ponemos a 0 el número de pulsos
  interrupts();    //Habilitamos las interrupciones
  delay(1000);   //muestra de 1 segundo
  noInterrupts(); //Desabilitamos las interrupciones
  frecuencia=NumPulsos; //Hz(pulsos por segundo)
  return frecuencia;
}

void setup()
{ 
  Serial.begin(9600); 
  pinMode(PinSensor, INPUT); 
  attachInterrupt(0,ContarPulsos,RISING); //(Interrupcion 0(Pin2),funcion,Flanco de subida)
} 

void loop ()    
{
  float frecuencia=ObtenerFrecuencia(); //obtenemos la Frecuencia de los pulsos en Hz
  float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
  float caudal_L_h=caudal_L_m*60; //calculamos el caudal en L/h

if(caudal_L_m == 0){
  
  Serial.print ("Caudal: "); 
  Serial.print (caudal_L_m,3);
  Serial.print (" L/m\t");
Serial.println ("LL0:llave cerrada");
}

else{  
   Serial.print ("Caudal: "); 
  Serial.print (caudal_L_m,3);
  Serial.print (" L/m\t");
Serial.println ("LL1:llave abierta");
  
  }
  
  
  
  }


