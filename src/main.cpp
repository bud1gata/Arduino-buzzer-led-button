#include <Arduino.h>

#define ledRed 2
#define ledGreen 3
#define btn 4
#define buzzer 5

void setup() {
  //button input
  pinMode(btn, INPUT);

  //btn
  digitalWrite(btn, HIGH);

  //led output
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void sound (int speed, int freq){
  tone(buzzer, freq);
  delay(speed);
  noTone(buzzer);
}

void gantiLampu (int lampu){
  if (lampu == 1)
  {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
    digitalWrite(buzzer, LOW);
  } else {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
    sound(300, 2000);
  }  
}

void loop() {
  int isButtonPush = digitalRead(btn);  
  if (isButtonPush == 1)
  {
    gantiLampu(1);   
  } else {
    gantiLampu(0);   
  }

}