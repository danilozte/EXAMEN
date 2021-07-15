// configuracion de varibles
int LED = 12;

void setup(){
    
    pinMode(LED, OUTPUT);
    Serial.begin(9600);

    int x = 1; // variable entera // tambien podemos combinar el while para poder cambiar las conf de los pines 

    while ( x < 5)
    {
        Serial.println ("Dentro Del While:");
        pinMode(x, OUTPUT);
        // delay(200);
        digitalWrite(x, HIGH);
        Serial.print(x);
        x++;
    }
    Serial.println("Ya estoy fuera del while");
    Serial.println("Ahora el valor de x = es :");
    Serial.println(x); // ?
} 


void loop(){ 
////
}

