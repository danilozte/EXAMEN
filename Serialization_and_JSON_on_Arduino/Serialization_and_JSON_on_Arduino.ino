float temperatura;
float humidity;
float timestamp;

void setup() {
  // put your setup code here, to run once:S
  Serial.begin(115200);

///////////////FORMA SIMPLE Y NATURAL///////

  //////SERIALIZATION/////
   /*
  Serial.Write(&temperature, sizeof(float));
  Serial.Write(&humidity, sizeof(float));
  Serial.Write(&timestamp, sizeof(long));
  temperatura = 4 bytes , humdity = 4 Bytes, timestamp = 4 Bytes
  */
  //////DESERIALIZATION////
  /*
  Serial.ReadBytes(&temperature, sizeof(float));
  Serial.ReadBytes(&humidity, sizeof(float));
  Serial.ReadBytes(&timestamp, sizeof(long));
  */
/// FORMA ESPECIFICA

  struct{
   float temperatura;
   float humidity;
   long timestamp;
   data;
  }
  
   //////SERIALIZATION/////
   /*
  Serial.Write(data,, sizeof(data));
  Serial.Write(data,, sizeof(data));
  Serial.Write(data,, sizeof(data));
  temperatura = 4 bytes , humdity = 4 Bytes, timestamp = 4 Bytes
  */
  //////DESERIALIZATION////
  /*
  Serial.ReadBytes(&data, sizeof(data));
  Serial.ReadBytes(&data, sizeof(data));
  Serial.ReadBytes(&data, sizeof(data));
  */
  
  
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
