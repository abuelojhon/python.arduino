// Definir variable 
int led = 13;
char comando;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()) {

    comando = Serial.read();

    if( comando == '1') {
      digitalWrite(led,HIGH);
    }
    else if (comando == '0'){
      digitalWrite(led,LOW);
    }
  }
}
