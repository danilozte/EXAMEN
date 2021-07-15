/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is almost the same as with the WiFi Shield library,
 *  the most obvious difference being the different file you need to include:
 */
#include "WiFi.h"

void setup()
{
    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println("Setup done");
}

void loop()
{
    Serial.println("scan start");// INICIAMOS A ESCANEAR LAS REDES

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks(); // GUARDAMOS EL NUMERO TOTAL DE RDES ENCONTRADAS
    Serial.println("scan done");
    if (n == 0) {  // PUEDA QUE NO ENCUENTRA NINGUNA RED; SI N ES O MUESTRA QUE NO ENCONTRO NINGUNA RED 
        Serial.println("no networks found");
    } else {
        Serial.print(n); // SI NO ES 0 ENTONCES IMPRIMO EL NUMERO DE REDES QUE ENCONTRE Y EL MENSAJE REDES ENCONTRADO. 
        Serial.println(" networks found"); // REDES ENCONTRADAS
        for (int i = 0; i < n; ++i) {  // UN CICLO FOR PARA MOSTRAR EL NOMBRE Y EL ENUMERADOR , UTILIZANDO LA VARIABLE (N CON LA CANTIDAD QUE TRAE DE CADA ESCANER)
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }
    Serial.println("");

    // Wait a bit before scanning again
    delay(5000);
}