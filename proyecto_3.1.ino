/*Proyecto 3: LDR (sensor de luz)
Objetivo
>> Enceder el led en  condiciones de poca luz y mostrar los datos en el monitor seriaL del IDE Arduino

Aprender a:
>> Leer un sensor analógico (LDR).
>> Convertir los valores de 0–1023 a una escala más práctica.
>> Usar esos valores para controlar LEDs o visualizar datos.

Materiales
>> Arduino Uno (o similar)
>> LDR (fotoresistor)
>> Resistencia de 10 kΩ (para crear divisor de voltaje)
>> LED (opcional)
>> Resistencia de 220 Ω para LED (opcional)
>>Protoboard y cables
*/

//declaracion de variable

int ledPin = 13;
int ldrPin = A0; //Pin analogico donde esta el LDR
int ldrValue; // Almacena el valor leido del sensor LDR


void setup() {
  // put your setup code here, to run once:

  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  // el puerto analogo (A0) actua como salida por defecto
}

void loop() {
  // put your main code here, to run repeatedly:

  // lee el valor del sensor y lo envia al terminal serial compredido entre 0-1023
  ldrValue = analogRead(ldrPin); 
  Serial.println(ldrValue);

  //Encender el led si la luz es baja
  if (ldrValue < 700 ) {
    digitalWrite(ledPin,HIGH); 
  }else{
    digitalWrite(ledPin,LOW);
  }

  delay(500);
}
