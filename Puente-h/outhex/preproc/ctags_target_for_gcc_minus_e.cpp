# 1 "c:\\Users\\asus\\Desktop\\Arduino\\Puente-h\\PuenteH.ino"
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

 pinMode(Btn, 0x0);
    pinMode(MotorAOut1, 0x1);
    pinMode(MotorAOut2, 0x1);
    pinMode(MotorBOut1, 0x1);
    pinMode(MotorBOut2, 0x1);
    pinMode(VelMotorA, 0x1);
    pinMode(VelMotorB, 0x1);


}
/*

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

    

}*/
# 55 "c:\\Users\\asus\\Desktop\\Arduino\\Puente-h\\PuenteH.ino"
void loop()
{

  int Btn_M = digitalRead(Btn);


      Serial.println(Btn_M);

    if(Btn_M == 0x0){
        digitalWrite(MotorAOut1, 0x0);
        digitalWrite(MotorAOut2, 0x1);
        analogWrite(VelMotorA, 255);


        digitalWrite(MotorBOut1, 0x0);
        digitalWrite(MotorBOut2, 0x1);
        analogWrite(VelMotorB, 255);

    }

   else if(Btn_M == 0x1){

        delay(100);
        digitalWrite(MotorAOut1, 0x1);
        digitalWrite(MotorAOut2, 0x0);
        analogWrite(VelMotorA, 255);

        digitalWrite(MotorBOut1, 0x1);
        digitalWrite(MotorBOut2, 0x0);
        analogWrite(VelMotorB, 255);
        Serial.println(Btn_M);

    }
    else{

        digitalWrite(MotorAOut1, 0x0);
        digitalWrite(MotorAOut2, 0x0);
        analogWrite(VelMotorA, 0);

        digitalWrite(MotorBOut1, 0x0);
        digitalWrite(MotorBOut2, 0x0);
        analogWrite(VelMotorB, 0);
        Serial.println();


    }



}
