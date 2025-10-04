//primer proyecto de IA con arduino y python
// ***Arduino mide la luz ambiental usando un LDR
// ***Python recibe los datos via Serial y predice la intesindad de luz o clasifica si es 
//   "Baja", "Media" o "Alta" usando un modelo de IA, Random Forest

const int ldrPin = A0;
const int ledRed = 2;
const int ledYellow = 3;
const int ledGreen = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0 ){
    String nivel = Serial.readStringUntil('\n');
    nivel.trim();

    digitalWrite(ledRed,LOW);
    digitalWrite(ledYellow,LOW);
    digitalWrite(ledGreen,LOW);

    if(nivel == "Baja") digitalWrite(ledRed,HIGH);
    else if(nivel == "Media") digitalWrite(ledYellow,HIGH);
    else if(nivel == "Alta") digitalWrite(ledGreen,HIGH);
  }
  
  int ldrValor = analogRead(ldrPin);
  Serial.println(ldrValor);
  delay(500);
}
