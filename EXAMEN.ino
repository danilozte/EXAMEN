int led = 27;
int led1 = 33;

void setup(){
Serial.begin (115200);
pinMode(led , OUTPUT);

}

void loop(){

digitalWrite( led , HIGH);
delay(200);
digitalWrite( led , LOW);
delay(200);  
digitalWrite( led1 , HIGH);
delay(200);
digitalWrite( led1 , LOW);
delay(200);
}