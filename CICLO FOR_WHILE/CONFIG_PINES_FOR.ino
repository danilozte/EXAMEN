// configuracion de varibles
int LED = 16;
void setup(){
    pinMode(LED,OUTPUT);
    Serial.begin(9600);
    for (int leds = 15; leds <= 18; leds++)
    {
        pinMode(leds,OUTPUT);/* instruccion  */
    }

     for (int leds = 15; leds <= 18; leds++)
    {
        digitalWrite(leds,HIGH);/* instruccion  */
    }
    
}

void loop(){
digitalWrite(LED,HIGH);
} //