#include <LiquidCrystal.h> //Biblioteca para un mejor uso del LCD

//Creación del objeto tipo LCD para utilizarlo físicamente
 LiquidCrystal lcd(10, 9, 8, 5, 4, 3, 2); //(RS, RW, E, D4,D5, D6, D7) 

 //Variables
 float volt;
 float temp;
 float RTD;
 float CAS;
 
 void setup()
 {
    Serial.begin(9600);
    lcd.noCursor();
    delay(500);
    lcd.begin(20, 4);               
 }
 
 void loop()
 {
    volt = analogRead(A0);
    CAS = (volt * 5) / 1024; //Salida del CAS
    volt = analogRead(A1);
    volt = (volt * 5) / 1024; //Lee El voltaje del RTD
    RTD = (1000 * volt) / (10 - volt)-1 ;//Resistencia de la RTD
    temp = ((RTD - 100) / (0.003983 * 100));//Temperatura
        
    lcd.setCursor(0, 0); //posicionar el cursor en las coordenadas 0,0
    lcd.print("CAS(V):"); //imprimir mensaje
    lcd.setCursor(10, 0);
    lcd.print(CAS);//Salida del CAS   

    lcd.setCursor(0, 1); //posicionar el cursor en las coordenadas 0,1
    lcd.print("RTD(Ohm):"); //imprimir mensaje
    lcd.setCursor(10, 1);
    lcd.print(RTD);//Voltaje en RTD

    lcd.setCursor(0, 2); //posicionar el cursor en las coordenadas 0,2
    lcd.print("Temp(C):"); //imprimir mensaje
    lcd.setCursor(10, 2);
    lcd.print(temp);//Temperatura    
       
    //Encender el cursor
    lcd.cursor();
    delay(500);
 }
