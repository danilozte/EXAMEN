#include <Arduino.h>
#include <ArduinoJson.h>

//si usas esp32
#include <HTTPClient.h>
#include <WiFi.h>

//si usas esp8266
//#include <ESP8266WiFiMulti.h>
//#include <ESP8266HTTPClient.h>

const char* ssid = "LAPRIVADA";
const char* password =  "Ainoa2014";
//variables globales
///////////////////
//String cuerpo_respuesta;


void setup() {
  delay(10);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  WiFi.status();
  Serial.print( WiFi.status());
  delay(4000);
  Serial.print("Conectando...");
  while (WiFi.status() != WL_CONNECTED) { //Check for the connection
    Serial.println("No");
    delay(500);
    Serial.print(".");
    WiFi.begin(ssid, password);
  }

  Serial.print("Conectado con éxito, mi IP es: ");
  Serial.println(WiFi.localIP());
  peticion();

}

void peticion() {

 
    // https://my.api.mockaroo.com/data.json?key=12806170
    HTTPClient http;
    http.begin("https://my.api.mockaroo.com/data.json?key=12806170");        //Indicamos el destino
    http.addHeader("Content-Type", "application/json"); //Preparamos el header text/plain si solo vamos a enviar texto plano sin un paradigma llave:valor.

    int codigo_respuesta = http.GET();   //Enviamos el post pasándole, los datos que queremos enviar. (esta función nos devuelve un código que guardamos en un int)

    if(codigo_respuesta>0){
      Serial.println("Código HTTP ► " + String(codigo_respuesta));   //Print return code

      if(codigo_respuesta == 200){
        String cuerpo_respuesta = http.getString();
        Serial.println("El servidor respondió ▼ ");
        Serial.println(cuerpo_respuesta);

         const size_t capacity = JSON_OBJECT_SIZE(3) + 60;
         DynamicJsonBuffer jsonBuffer(capacity);
         JsonObject& root = jsonBuffer.parseObject(cuerpo_respuesta);

         //StaticJsonBuffer<200> JsonBuffer;
         //JsonObject& root = JsonBuffer.parseObject(cuerpo_respuesta);
  
        if (!root.success()) {
        Serial.println("parseObject() failed");
        return;
       }

        //{"id":null,"first_name":"Doralynn","last_name":"Baumford"}

        const char* first_name = root["first_name"]; // "first_name"
        const char* last_name =  root["last_name"]; // "last_name"

        Serial.println(first_name);
        Serial.println(last_name);

       delay(5000);

    }

    }else{

     Serial.print("Error enviando POST, código: ");
     Serial.println(codigo_respuesta);

    }

    

  
  
 
}


void loop(){
 

}


