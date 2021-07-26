#include <ArduinoJson.h>

void setup() {
  Serial.begin(9600);
  const char* input = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";
  StaticJsonDocument<256> doc;
  DeserializationError error = deserializeJson(doc, input);

  if(error){
    Serial.print("ERROR:");
    Serial.print(error.c_str());
    return;
    }



  const char* sensor = doc["sensor"];
  long time = doc["time"];
  float lat = doc["data"][0];
  float lon = doc["data"][1];
  delay(100);
  
  Serial.println("......... :");
  Serial.print("SENSOR :");
  Serial.println(sensor);
  
  Serial.print("TIME :");
  Serial.println(time);
   
  Serial.print("LAT :");
  Serial.println(lat,6);
  Serial.print("LON :");
  Serial.println(lon,6);
}
void loop() {

}
