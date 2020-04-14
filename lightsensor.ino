int led1 = A5; 
int led2 = D7; 
int lightSensor = A0;
int analogValue;

void setup() {

  

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(lightSensor, INPUT);

}

void loop() {

    analogValue = analogRead(lightSensor);
    if (analogValue < 15){
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        Particle.publish("analogValue", String(analogValue), PRIVATE);
        delay(30000);

    }
    else{
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        Particle.publish("analogValue", String(analogValue), PRIVATE);
        delay(30000);
    }
}