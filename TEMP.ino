
int Vo;
float R1 = 10000;              // resistencia fija del divisor de tension 
float logR2, R2, TEMPERATURA;
float c1 = 2.108508173e-03, c2 = 0.7979204727e-04, c3 = 6.535076315e-07;
// coeficientes de S-H en pagina: 
// http://www.thinksrs.com/downloads/programs/Therm%20Calc/NTCCalibrator/NTCcalculator.htm

void setup() {
Serial.begin(9600);		// inicializa comunicacion serie a 9600 bps
}

void loop() {
  Vo = analogRead(26);			// lectura de A0
  R2 = R1 * (4094.0 / (float)Vo - 1.0);	// conversion de tension a resistencia
  logR2 = log(R2);			// logaritmo de R2 necesario para ecuacion
  TEMPERATURA = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)); 	// ecuacion S-H
  TEMPERATURA = TEMPERATURA - 273.15;   // Kelvin a Centigrados (Celsius)

  Serial.print("Temperatura: "); 	// imprime valor en monitor serie
  Serial.print(TEMPERATURA);
  Serial.println("C"); 
  delay(500);				// demora de medio segundo entre lecturas
}