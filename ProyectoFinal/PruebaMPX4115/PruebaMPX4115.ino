 #include <LiquidCrystal.h>

 LiquidCrystal lcd(10, 9, 8, 5, 4, 3, 2); //(RS, RW, E, D4,D5, D6, D7) 

float volt;
float CAS;
float E1;
float E2;

 void setup(){
    Serial.begin(9600);
    lcd.noCursor();
    delay(500);
    lcd.begin(20, 4);
 }
 
 void loop(){
    volt = analogRead(A0);
    CAS = (volt * 5) / 1024;
    volt = analogRead(A1);
    E1 = (volt * 5) / 1024;
    E2 = (((E1 / 5.1) + 0.095) / 0.009);

    lcd.setCursor(0, 0); //Posición del renglón
    lcd.print("Vo CAS(V):"); //Mensaje
    lcd.setCursor(11 ,0); //Posición del cursor
    lcd.print(CAS); //Imprimir valor

    lcd.setCursor(0,1); //Posición del renglón
    lcd.print("Vo Sensor(V):"); //Mensaje
    lcd.setCursor(14,1); //Posición del cursor
    lcd.print(E1); //Imprimir valor

    lcd.setCursor(0,2); //Posición del renglón
    lcd.print("Presion (kPa):"); //Mensaje
    lcd.setCursor(15,2); //Posición del cursor
    lcd.print(E2); //Imprimir valor
    
    lcd.cursor();
    delay(500);
 }
