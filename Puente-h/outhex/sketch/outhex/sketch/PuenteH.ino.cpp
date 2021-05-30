#include <Arduino.h>
#line 1 "c:\\Users\\asus\\Desktop\\Arduino\\Motor_A\\Puente-h\\PuenteH.ino"
//Puente-H control Arduino


int MotorAOut1 = 3;
int MotorAOut2 = 4;
int MotorBOut1 = 5;
int MotorBOut2 = 6;
int time = 100;

int VelMotorA = 7;
int VelMotorB = 8;

int Btn = 2;

void setup()
{
    Serial.begin(9600);

	pinMode(Btn, INPUT);
    pinMode(MotorAOut1, OUTPUT);
    pinMode(MotorAOut2, OUTPUT);
    pinMode(MotorBOut1, OUTPUT);
    pinMode(MotorBOut2, OUTPUT);
    pinMode(VelMotorA, OUTPUT);
    pinMode(VelMotorB, OUTPUT);


}

void adelante(){

    digitalWrite(MotorAOut1, LOW);
    digitalWrite(MotorAOut2, HIGH);
    analogWrite(VelMotorA, 255);
   

    digitalWrite(MotorBOut1, LOW);
    digitalWrite(MotorBOut2, HIGH);
    analogWrite(VelMotorB, 255);
  
}

void atras(){

    digitalWrite(MotorAOut1, HIGH);
    digitalWrite(MotorAOut2, LOW);
    analogWrite(VelMotorA, 255);

    digitalWrite(MotorBOut1, HIGH);
    digitalWrite(MotorBOut2, LOW);
    analogWrite(VelMotorB, 255);
    
}

void stop(){

    digitalWrite(MotorAOut1, LOW);
    digitalWrite(MotorAOut2, LOW);
    analogWrite(VelMotorA, 255);

    digitalWrite(MotorBOut1, LOW);
    digitalWrite(MotorBOut2, LOW);
    analogWrite(VelMotorB, 255);

}

/*
void loop()
{

  int Btn_M = digitalRead(Btn);

     
      Serial.println(Btn_M);

    if(Btn_M == LOW){
        digitalWrite(MotorAOut1, LOW);
        digitalWrite(MotorAOut2, HIGH);
        analogWrite(VelMotorA, 255);
    

        digitalWrite(MotorBOut1, LOW);
        digitalWrite(MotorBOut2, HIGH);
        analogWrite(VelMotorB, 255);

    }

   else if(Btn_M == HIGH){

        delay(100);
        digitalWrite(MotorAOut1, HIGH);
        digitalWrite(MotorAOut2, LOW);
        analogWrite(VelMotorA, 255);

        digitalWrite(MotorBOut1, HIGH);
        digitalWrite(MotorBOut2, LOW);
        analogWrite(VelMotorB, 255);
        Serial.println(Btn_M);
    
    }
    else{

        digitalWrite(MotorAOut1, LOW);
        digitalWrite(MotorAOut2, LOW);
        analogWrite(VelMotorA, 0);

        digitalWrite(MotorBOut1, LOW);
        digitalWrite(MotorBOut2, LOW);
        analogWrite(VelMotorB, 0);
        Serial.println();

    
    }
    

    
}
*/

void loop(){

    int Btn_M = digitalRead(Btn);

     
      Serial.println(Btn_M);

      if(Btn_M == HIGH){

          adelante();
          delay(time);
      }
      else if(Btn_M == LOW){

          atras();
          delay(time);
      }
      else{
          stop();
      }

}
