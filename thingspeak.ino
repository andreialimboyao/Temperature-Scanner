#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//Declaring variables to represent each pin
int proxPin = 5;
int greenLED = 7;
int redLED = 6;
int buzzPin = 8;

double  bodyTemp, totalTemp, averageTemp;

void setup(){
  pinMode(proxPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzPin, OUTPUT);

  Serial.begin(9600);
  mlx.begin();         //Initialize MLX90614
}

void loop() {
  if(digitalRead(proxPin) == LOW){
    totalTemp = 0;

    for (int i = 0; i < 100; i++){
      bodyTemp= mlx.readObjectTempC()+3;
      totalTemp += bodyTemp;
      delay(1);
    }
    averageTemp = totalTemp/100.0;
    Serial.println(averageTemp);
    delay(50);
  
    if(averageTemp > 37.5){
      digitalWrite(buzzPin, HIGH);
      delay(10);
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW);
    }
    else if(averageTemp <= 37.5){
      digitalWrite(buzzPin, HIGH);
      delay(10);
      digitalWrite(buzzPin, LOW);
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, LOW);
    }  
    delay(15000);
   // tone(buzzPin, 10);
    digitalWrite(buzzPin, HIGH);
    delay(400);
   // noTone(buzzPin);
    digitalWrite(buzzPin, LOW);
  }
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
}
