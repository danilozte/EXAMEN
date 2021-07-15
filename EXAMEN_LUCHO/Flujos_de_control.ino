// EXAMEN DE FLUJO DE CONTROL//
//has un codigo que lea el puerto analogico por 2 segundos y te saque el promedio de la lectura //
#define promedio // difinimos una variable para guardar el promedio del valor leido en tiempo estimado de un potenciometro...
int valor;
int led   = 32;
int led_value;

void setup (){
    Serial.begin(9600);
    pinMode(led, OUTPUT);
}


void loop (){

 valor = analogRead(12);
 led_value = (valor/1023);
 Serial.print("el valor analogico es:");
 Serial.println(valor);
 delay(200);
 Serial.print("el valor de voltaje  es:");
 Serial.println(led_value);
 delay(200);


}
 
 
  //for (led_value =0; led_value<=255; led_value++){

    //digitalWrite (led,led_value);
    //delay(200); 
   //}
