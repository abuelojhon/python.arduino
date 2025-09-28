
/*Proyecto 1: LED parpadeante

Objetivo 
Aprender a:
>> Encender y apagar un LED usando Arduino.
>> Controlar la duración de encendido/apagado con delay().
>> Familiarizarte con la sintaxis básica de Arduino.

Materiales
>> Arduino Uno (o similar)
>> LED
>> Resistencia de 220 Ω
>> Cables de conexión
>> Protoboard (opcional)
*/

int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(ledPin,OUTPUT); // Configuro el pin 13 como salida
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(ledPin,HIGH); //encendido led
  delay(1000); //retraso de 1000 mseg = 1seg
  digitalWrite(ledPin,LOW); //apagar led
  delay(1000); // espera 1 seg
}
