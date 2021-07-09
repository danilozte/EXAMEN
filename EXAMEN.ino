int led = 27;

void setup(){
Serial.begin (115200);
pinMode(led , OUTPUT);

}

void loop(){

digitalWrite( led , HIGH);
delay(200);
digitalWrite( led , LOW);
delay(200);  

}