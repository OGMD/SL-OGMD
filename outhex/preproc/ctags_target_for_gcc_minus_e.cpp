# 1 "c:\\Users\\asus\\Desktop\\Arduino\\Motor_A\\Motor_A.ino"
//Control de motor con push button

int Btn_M1 = 2;
int Btn_Paro = 3;
int Motor1 = 6;
int Motor2 = 7;
int Led_M1 = 22;
int Led_M2 = 23;
int Led_Paro = 24;
int time = 250;

//variables sensor IR

int led_ir = 8;
int val_ir_pin = 9;
int val_ir=0;


void setup()
{

    //Entradas
 pinMode(Btn_M1, 0x0);
    pinMode(Btn_Paro, 0x0);


    //Salidas
    pinMode(Motor1, 0x1);
    pinMode(Motor2, 0x1);
    pinMode(Led_M1, 0x1);
    pinMode(Led_M2, 0x1);
    pinMode(Led_Paro, 0x1);


    //pinmode sensor IR
    pinMode(led_ir,0x1);
    pinMode(val_ir_pin, 0x0);
    Serial.begin(9600);
}

void loop()
{

    //Ir loop sensor

    val_ir=digitalRead(val_ir_pin);
    digitalWrite(led_ir, val_ir);
    Serial.println(val_ir);




    //motors

    int value_entry = digitalRead(Btn_M1);
    int value_exit = digitalRead(Btn_Paro);

    if(value_exit == 0x1){

        digitalWrite(Motor1, 0x0);
        digitalWrite(Motor2, 0x0);
        digitalWrite(Led_M1, 0x0);
        digitalWrite(Led_M2, 0x0);
        digitalWrite(Led_Paro, 0x1);

    }else{

        if( value_entry == 0x1){

            digitalWrite(Led_Paro, 0x0);

                digitalWrite(Motor1,0x1);
                digitalWrite(Led_M1, 0x1);
                delay(time);
                digitalWrite(Motor2, 0x0);
                digitalWrite(Led_M2, 0);
        }
        else if(value_entry == 0x0){

            digitalWrite(Led_Paro, 0x0);

                digitalWrite(Motor2, 0x1);
                digitalWrite(Led_M2, 0x1);
                delay(time);
                digitalWrite(Motor1, 0x0);
                digitalWrite(Led_M1, 0);
        }
        else

            digitalWrite(Led_Paro, 0x1);
            digitalWrite(Motor1, 0x0);
            digitalWrite(Motor2, 0x0);
        }

    }
