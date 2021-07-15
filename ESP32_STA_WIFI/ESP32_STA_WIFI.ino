
#include <WiFi.h>;

const char* ssid = "LAPRIVADA";
const char* password = "Ainoa2014";

void setup()
{
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    Serial.print("Conecting to WIFI");

    while (WiFi.status() != WL_CONNECTED)
    {
       Serial.print(".");
       delay(500);
    }
    
    Serial.println("\nConnectado a una red WIFI");
    Serial.print("Direccion IP: ");
    Serial.println(WiFi.localIP());
}

void loop(){
    if (( WiFi.status() == WL_CONNECTED))
    {
        Serial.println("Tu puedes hacer pin");
        delay(5000);
    }
    else
    {
        Serial.println(" No se puede conectar");
    }
    

}


