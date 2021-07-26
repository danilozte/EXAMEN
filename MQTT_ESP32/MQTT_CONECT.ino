#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <WebServer.h>
#include <ArduinoJson.h>

//**************************************
//*********** MQTT CONFIG **************
//**************************************
const char *mqtt_server = "ioticos.org"; //Este es el host donde nos vamos a conectar.
const int mqtt_port = 1883;              // puerto del host
const char *mqtt_user = "GN6Syw1WklvUdMF";
const char *mqtt_pass = "CH5d1QQ7DS89yR5";
const char *root_topic_subscribe = "cxSjqrPrn9NT41G/input";
const char *root_topic_publish = "cxSjqrPrn9NT41G/output";


const int PUBLISH_FREQUENCY = 2000; // Update rate in milliseconds
unsigned long timer;
const char name[32] = "";


//**************************************
//*********** WIFICONFIG ***************
//**************************************
const char *ssid = "LA_PRIVADA_A";
const char *password = "Ainoa2014";

const char *user = "LAPRIVADA";
const char *contra = "Ainoa2014";

//******************************************************
//*********** DEFINIMOS NUESTRA IP LOCAL ***************
//******************************************************
IPAddress ip(192, 168, 4, 22);      // (192,168,1,1)
IPAddress gateway(192, 168, 4, 9);  // (192,168,1,1)
IPAddress subnet(255, 255, 255, 0); // (255,255,255,0)

WebServer server(80); //PUERTO POR DEFECTO

//**************************************
//*********** GLOBALES   ***************
//**************************************
WiFiClient espClient;
PubSubClient client(espClient);
char msg[25];
long count = 0;
bool Mode_AP = true;
bool releState = true;
float latitud;
float longitud;

int LED = 17;
int LED2 = 34;
int LED3 = 27;

//************************
//** F U N C I O N E S ***
//************************
void callback(char *topic, byte *payload, unsigned int length);
void reconnect();
void setup_WiFi();

//*****************************
//***       CALLBACK        ***
//*****************************

void callback(char *topic, byte *payload, unsigned int length)
{

  // "{"sensor":"gps","time":1351824120,"data":[48.756080,2.302038]}";
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  Serial.println(length);

  String incoming = "";
  for (int i = 0; i < length; i++)
  {
    incoming += ((char)payload[i]); 
  }

  Serial.println("mensaje" + incoming);

  StaticJsonDocument<256> doc;
  DeserializationError error = deserializeJson(doc, incoming);    // deserializeJson(doc,incoming); can use string instead of payload
   
  if(error){
    Serial.print("ERROR:");
    Serial.print(error.c_str());
    return;
    }

  const char *sensor = doc["sensor"]; // "gps"
  long time = doc["time"];            // 1351824120
  float longitud = doc["data"][0];    // 48.75608
  float latitud = doc["data"][1];     // 2.302038

  Serial.println(sensor);
  Serial.println(time);
  Serial.println(longitud, 6);
  Serial.println(latitud, 6);
  
   if (latitud == 2.302038)
  {
    digitalWrite(LED2, HIGH);
  }
  if ( longitud == 48.75608 )
  {
    digitalWrite(LED3, HIGH);
    
  }
  
  client.loop();
 
}

void setup()
{
 
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  uint8_t analogPin = 34; // Pin used to read data from GPIO34 ADC_CH6.
  //timer = millis();


  //****************************************************************
  //** F U N C I O N E S DE MODO DE CONEXION WiFi ******************
  //****************************************************************

/*
  WiFi.softAP(ssid, password); //funcion de conexion WiFi AP
  IPAddress ip = WiFi.softAPIP();
  Serial.print("Nombre de mi red esp32:");
  Serial.println(ssid);
  Serial.print("la IP es:");
  Serial.println(ip);

  server.on("/", handleConnectionRoot);
  server.on("/relayOn", handleRelayOn);
  server.on("/relayOff", handleRelayOff);
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("Servidor HTTP iniciando");
*/
  



  //********************************************
  //** F U N C I O N E S PARA MQTT *************
  //********************************************
  setup_WiFi(); //esta funciona,me contecto a la red WIFi local osea STA
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() // Aqui se encuentra la  funcion de reconexion para no perder la conexion con el hosting
{
 
  if (!client.connected())
  {
    reconnect();
  }
  /*
  if (client.connected()){
    String str = "La cuenta es -> " + String(count);
    str.toCharArray(msg,25);
    client.publish(root_topic_publish,msg);
    count++;
    delay(5000);
  }
  

  //ubidots.subscribeLastValue(DISP_VARIABLE_LABEL, VARIABLE_LABEL2); // Insert the dataSource and Variable's Labels
  */
 client.loop();
}



//*****************************
//***    CONEXION WIFI  STA    ***
//*****************************
void setup_WiFi()
{
  delay(10);
  // Nos conectamos a nuestra red WiFi
  Serial.println();
  Serial.print("Conectando a ssid: ");
  Serial.println(user);

  WiFi.begin(user, contra);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Conectado a red WiFi!");
  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP());
}

//*****************************
//***    CONEXION MQTT      ***
//*****************************

void reconnect()
{

  while (!client.connected())
  {
    Serial.print("Intentando conexión Mqtt...");
    // Creamos un cliente ID
    String clientId = "IOTICOS_H_W_"; // tener en cuneta el string del nombre del cliente
    clientId += String(random(0xffff), HEX);
    // Intentamos conectar
    if (client.connect(clientId.c_str(), mqtt_user, mqtt_pass))
    {
      Serial.println("Conectado!");
      // Nos suscribimos
      if (client.subscribe(root_topic_subscribe))
      {
        Serial.println("Suscripcion ok");
        digitalWrite(LED, HIGH);
      }
      else
      {
        Serial.println("fallo Suscripciión");
      }
    }
    else
    {
      Serial.print("falló :( con error -> ");
      Serial.print(client.state());
      Serial.println(" Intentamos de nuevo en 5 segundos");
      delay(5000);
    }
  }
}

// mensaje html para mostrar por ip 192.168.4.1
String answer = "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<meta charset=\"UTF-8\">\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n<title>Relay Control | AP</title>\n\n<style>\nbody {\nmargin: 0px auto;\ntext-align: center;\nfont-family: Helvetica;\n}\n#title{\nmargin-top: 50px;\nmargin-bottom: 15px;\ncolor: rgb(14, 14, 14);\n}\n\n#subtitle{\nmargin-top: 0;\nmargin-bottom: 25px;\ncolor: dimgray;\n}\n\n.onBtn {\nbackground-color:#44c767;\nborder-radius:28px;\nborder:1px solid #18ab29;\ndisplay:inline-block;\ncursor:pointer;\ncolor:#ffffff;\nfont-family:Arial;\nfont-size:17px;\npadding:16px 35px;\ntext-decoration:none;\ntext-shadow:0px 1px 0px #2f6627;\nmargin-right: 50px;\n}\n.onBtn:hover {\nbackground-color: #04e335;\n}\n.onBtn:active {\nposition:relative;\ntop:1px;\n}\n\n.offBtn {\nbackground-color:#f05d67;\nborder-radius:28px;\nborder:1px solid #e84165;\ndisplay:inline-block;\ncursor:pointer;\ncolor:#ffffff;\nfont-family:Arial;\nfont-size:17px;\npadding:16px 35px;\ntext-decoration:none;\ntext-shadow:0px 1px 0px #7a1515;\n}\n.offBtn:hover {\nbackground-color:#f22954;\n}\n.offBtn:active {\nposition:relative;\ntop:1px;\n}\n\n    </style>\n\n</head>\n<body>\n<div>\n<h1 id=\"title\">SERVIDOR WEB ESP32</h1>\n<h3 id=\"subtitle\">Modo Estación (STA)</h3>\n</div>\n<a href=\"/relayOn\" class=\"onBtn\">ON</a>\n<a href=\"/relayOff\" class=\"offBtn\">OFF</a>\n\n</body>\n</html>";

//***********************************
//***       RESPUESTA DE HTML  ******
//***********************************

void handleConnectionRoot()
{
  server.send(200, "text/html", answer);
}

void handleRelayOn()
{
  releState = true;
  server.send(200, "text/html", answer);
}

void handleRelayOff()
{
  releState = false;
  server.send(200, "text/html", answer);
}

void handleNotFound()
{
  server.send(404, "text/plain", "Not found");
}