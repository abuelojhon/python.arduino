/*Proyecto: LDR con control de LED y visualización en Python
Objetivo

>> Leer la luz ambiente con un LDR.
>> Ajustar el brillo de un LED según la cantidad de luz.
>> Enviar los datos a Python para graficarlos en tiempo real.

🔹Parte 1: Arduino
Conexión
>> LDR:
  Un extremo → 5 V
  Otro extremo → A0
  Resistencia de 10 kΩ → de A0 a GND

>> LED:
  Ánodo → Pin 9 (PWM)
  Cátodo → Resistencia 220 Ω → GND
*/

//Declaracion de variable
int ldrPin = A0;
int ledPin = 9; //led en pin PWM
int ldrValue = 0;
int brillo = 0; //Brillo Led(0-255)

void setup() {
  // put your setup code here, to run once:
   
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); // configurar el pin 9 como salidad (PWM) ancho de pulso
}

void loop() {
  // put your main code here, to run repeatedly:

  ldrValue = analogRead(ldrPin);
  brillo = map(ldrValue,0,1023,255,0); // convierte la salida LDR(0-1023) -> PWM(0-255)
  analogWrite(ledPin,brillo);

  // enviar el valor por serial a python
  Serial.println(ldrValue);

  delay(1000);
}
