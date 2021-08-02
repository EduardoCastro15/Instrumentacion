 #include <LiquidCrystal.h>

 LiquidCrystal lcd(10, 9, 8, 5, 4, 3, 2); //(RS, RW, E, D4,D5, D6, D7) 

float volt;
float CAS;
float E1;
float E2;
float vNTC;
float Celsius;
float Kelvin;
float RTC;

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
    volt = analogRead(A2);
    E2 = (volt * 5) / 1024;

    vNTC = E1 - E2;
    Celsius = vNTC / 0.05472;
    Kelvin = Celsius + 273;
    RTC = 10000 * pow(2.7182, 3977 * (pow(Kelvin, -1) - pow(298, -1)));
    
    lcd.setCursor(0, 0); //Posición del renglón
    lcd.print("Voltaje CAS(V):"); //Mensaje
    lcd.setCursor(16 ,0); //Posición del cursor
    lcd.print(CAS); //Imprimir valor

    lcd.setCursor(0,1); //Posición del renglón
    lcd.print("Voltaje WS(V):"); //Mensaje
    lcd.setCursor(15,1); //Posición del cursor
    lcd.print(vNTC); //Imprimir valor

    lcd.setCursor(0,2); //Posición del renglón
    lcd.print("T(C,K):"); //Mensaje
    lcd.setCursor(8,2); //Posición del cursor
    lcd.print(Celsius); //Imprimir valor
    lcd.setCursor(12,2); //Posición del cursor
    lcd.print(","); //Imprimir valor
    lcd.setCursor(14,2); //Posición del cursor
    lcd.print(Kelvin); //Imprimir valor

    lcd.setCursor(0,3); //Posición del renglón
    lcd.print("RTC(ohm):"); //Mensaje
    lcd.setCursor(10,3); //Posición del cursor
    lcd.print(RTC); //Imprimir valor
    
    lcd.cursor();
    delay(500);
 }
