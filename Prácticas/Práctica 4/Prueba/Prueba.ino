 #include <LiquidCrystal.h> //Biblioteca para un mejor uso del LCD

//Creación del objeto tipo LCD para utilizarlo físicamente
 LiquidCrystal lcd(10, 9, 8, 5, 4, 3, 2); //(RS, RW, E, D4,D5, D6, D7) 

 //Variables
 float analogValue;
 float analogValue2;
 float CAS;
 float frequencyVoltage;
 float frequency;
 
 void setup()
 {
    Serial.begin(9600);
    lcd.noCursor();
    delay(500);
    lcd.begin(20, 4);               
 }
 
 void loop()
 {
    analogValue = analogRead(A0);//Lee la salida del CAS
    analogValue2 = analogRead(A1);//Lee la salida del LM331
    
    CAS = analogValue*(5.0/1023.0); //Salida del CAS
    frequencyVoltage = analogValue2*(5.0/1023.0);   //Salida del convertidor LM331
    frequency = (frequencyVoltage*(0.17)*(1.0/2.09)*(1/(6.81*pow(10,-5))))+10.0; //Valor de frecuencia            
    
    lcd.setCursor(0, 0); //posicionar el cursor en las coordenadas 0,0
    lcd.print("Salida CAS:"); //imprimir mensaje
    lcd.setCursor(12 ,0);
    lcd.print(CAS);//Salida del CAS
    lcd.setCursor(16,0);
    lcd.print("V");    

    lcd.setCursor(0,1);
    lcd.print("Frecuencia:"); 
    lcd.setCursor(12,1);
    lcd.print(frequency); //Frecuencia
    lcd.setCursor(18,1);
    lcd.print("Hz"); 

    lcd.setCursor(0,2);
    lcd.print("Salida LM331:"); 
    lcd.setCursor(15,2);
    lcd.print(frequencyVoltage);
    lcd.setCursor(18,2);
    lcd.print("V"); 
        
    //Encender el cursor
    lcd.cursor();
    delay(500);
 }
