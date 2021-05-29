//OGMD Version code 1.0
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
	pinMode(Btn_M1, INPUT);
    pinMode(Btn_Paro, INPUT);


    //Salidas
    pinMode(Motor1, OUTPUT);
    pinMode(Motor2, OUTPUT);
    pinMode(Led_M1, OUTPUT);
    pinMode(Led_M2, OUTPUT);
    pinMode(Led_Paro, OUTPUT);


    //pinmode sensor IR
    pinMode(led_ir,OUTPUT);
    pinMode(val_ir_pin, INPUT);
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

    if(value_exit == HIGH){

        digitalWrite(Motor1, LOW);
        digitalWrite(Motor2, LOW);
        digitalWrite(Led_M1, LOW);
        digitalWrite(Led_M2, LOW);
        digitalWrite(Led_Paro, HIGH);

    }else{

        if( value_entry == HIGH){

            digitalWrite(Led_Paro, LOW);

                digitalWrite(Motor1,HIGH);
                digitalWrite(Led_M1, HIGH);
                delay(time);
                digitalWrite(Motor2, LOW);
                digitalWrite(Led_M2, 0);
        }
        else if(value_entry == LOW){

            digitalWrite(Led_Paro, LOW);

                digitalWrite(Motor2, HIGH);
                digitalWrite(Led_M2, HIGH);
                delay(time);
                digitalWrite(Motor1, LOW);
                digitalWrite(Led_M1, 0);
        }
        else
            
            digitalWrite(Led_Paro, HIGH);
            digitalWrite(Motor1, LOW);
            digitalWrite(Motor2, LOW);
        }
    
    }
    
	

