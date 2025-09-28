/*Proyecto 2: Botón con LED
Objetivo

Aprender a:
>> Leer la entrada de un botón (digital).
>> Usar condicionales para controlar un LED.
>> Entender la diferencia entre entrada y salida digital en Arduino.

Materiales

>> Arduino Uno (o similar)
>> LED
>> Resistencia de 220 Ω para el LED
>> Botón pulsador
>> Resistencia de 10 kΩ para el botón (pull-down)
>> Cables y protoboard
*/

// declaracion de variable
int ledPin = 13;
int buttonPin = 2; // boton conectado al pin 2
int estado = 0; //variable para leer el estado del boton

void setup() {
  // put your setup code here, to run once:

  pinMode(ledPin,OUTPUT); // Se configura como salida
  pinMode(buttonPin,INPUT); // se configura como entrada para el boton
  
}

void loop() {
  // put your main code here, to run repeatedly:

  estado = digitalRead(buttonPin);
  delay(50); // un retraso de 50 mseg para darle tiempo que se estabilice la senal de entrada
  
  if (estado == HIGH) {
    digitalWrite(ledPin,HIGH);  
  }
  else{
    digitalWrite(ledPin,LOW);
  }
}
