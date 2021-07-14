int cont = 0;
int pull = 11;
double VALUE2; 
int   led = 10;
unsigned long prev; 



void setup() {
  Serial.begin(9600);
  Serial.println("iniciando..");
  pinMode(pull,INPUT);
  pinMode(led,OUTPUT);
  prev = 0;
  
}

void loop() {
 
while (millis()- prev <= 5000){
     VALUE2 = VALUE2 + analogRead(32)*(5.0/1023.0);
     Serial.println(VALUE2 );
     cont++;
     Serial.println(cont);
  }

 if (digitalRead(11) == HIGH){
    digitalWrite (10, HIGH);
  
  }
  else{
  digitalWrite (10 ,LOW);  
    }
    
  float VOLT = (VALUE2/cont);
  Serial.print("el promedio es:");
  Serial.println (VOLT);  
  delay(400);
}
