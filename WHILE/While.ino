// configuracion de varibles
int LED = 12;

void setup(){

    pinMode(LED, OUTPUT);
    Serial.begin(9600);

    int x = 15; // variable entera // tambien podemos combinar el while para poder cambiar las conf de los pines 

    while ( x < 20){
    
        pinMode(x, OUTPUT);
        // delay(200);
        digitalWrite(x, HIGH);
        Serial.print(x);
        Serial.println ("Dentro Del While:");
        x++;
    }
    Serial.println("Ya estoy fuera del while");
    Serial.println("Ahora el valor de x = es :");
    Serial.println(x); // ?
} 


void loop(){ 
////
}

