int TEMPERATURA = 0; 
int led1 =  27;
int led2 = 33;
int led3 = 33;


void setup(){
Serial.begin (115200);
pinMode(led1 , OUTPUT);
pinMode(led2 , OUTPUT);
pinMode(led3 , OUTPUT);

}




void loop(){

switch (TEMPERATURA) {
  case 0:  digitalWrite( led1 , HIGH); 
           digitalWrite( led2 , HIGH);///
           delay(200);
    
    break;
  case 2:  digitalWrite( led2 , HIGH);   
           digitalWrite( led3 , HIGH);
           delay(200);
   
    break;

  case 3: 
           digitalWrite( led1 , HIGH);   
           digitalWrite( led2 , HIGH);
           digitalWrite( led3 , HIGH);
           delay(200);
   
    break;
  default:
          Serial.println ("NINGUNA DE LAS ANTERIORES");
    break;// Termina  el switch si no se cumple ninguno de los casos
}
}
