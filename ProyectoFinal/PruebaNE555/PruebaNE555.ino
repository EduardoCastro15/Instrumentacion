 #include <LiquidCrystal.h>

 LiquidCrystal lcd(10, 9, 8, 5, 4, 3, 2); //(RS, RW, E, D4,D5, D6, D7) 

 //Variables
 float analogValue;
 float analogValue2;
 float CAS;
 float frequencyVoltage;
 float frequency;
 
 void setup(){
    Serial.begin(9600);
    lcd.noCursor();
    delay(500);
    lcd.begin(20, 4);               
 }
 
 void loop(){
    analogValue = analogRead(A0); //Lee la salida del CAS
    analogValue2 = analogRead(A1); //Lee la salida del LM331
    
    CAS = analogValue*(5.0/1023.0); //Voltaje de salida del CAS
    frequencyVoltage = analogValue2*(5.0/1023.0); //Votlaje de salida del convertidor LM331
    frequency = (frequencyVoltage*(0.17)*(1.0/2.09)*(1/(6.81*pow(10,-5))))+10.0; //Frecuencia de oscilación del NE555           
    
    lcd.setCursor(0, 0); //Posición del renglón
    lcd.print("Salida CAS:"); //Mensaje
    lcd.setCursor(12 ,0); //Posición del cursor
    lcd.print(CAS); //Imprimir valor
    lcd.setCursor(16,0); //Posición del cursor
    lcd.print("V"); //Mensaje

    lcd.setCursor(0,1); //Posición del renglón
    lcd.print("Frecuencia:"); //Mensaje
    lcd.setCursor(12,1); //Posición del cursor
    lcd.print(frequency); //Imprimir valor
    lcd.setCursor(18,1); //Posición del cursor
    lcd.print("Hz"); //Mensaje

    lcd.setCursor(0,2); //Posición del renglón
    lcd.print("Salida LM331:"); //Mensaje
    lcd.setCursor(15,2); //Posición del cursor
    lcd.print(frequencyVoltage); //Imprimir valor
    lcd.setCursor(18,2); //Posición del cursor
    lcd.print("V"); //Mensaje
    
    lcd.cursor();
    delay(500);
 }
