// configuracion de varibles
int LED = 16;
void setup(){
    pinMode(LED,OUTPUT);
    Serial.begin(9600);

    int x = 15; // variable entera // tambien podemos combinar el while para poder cambiar las conf de los pines 

    while ( x < 19)
    {
        Serial.println ("Dentro Del While");
        pinMode(x, OUTPUT);
        // delay(200);
        digitalWrite(x, HIGH);
        Serial.println(x);
        x++;
    }
    Serial.println("Ya estoy fuera del while");
    
}

void loop(){
}
    /*
digitalWrite(LED,HIGH);
delay(200);
digitalWrite(LED,LOW);
delay(200);
}
*/

