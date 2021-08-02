 #include <LiquidCrystal.h>

 LiquidCrystal lcd(10, 9, 8, 5, 4, 3, 2); //(RS, RW, E, D4,D5, D6, D7) 

 void setup(){
    Serial.begin(9600);
    lcd.noCursor();
    delay(500);
    lcd.begin(20, 4);               
 }
 
 void loop(){
    float volt = analogRead(A0);
    float CAS = (volt * 5) / 1024;
    volt = analogRead(A1);
    float VBE = (volt * 5) / 1024;
    float Celsius = ((VBE - 0.58) / (-0.002234)) + 25;
    float Kelvin = Celsius + 273.15;
    
    lcd.setCursor(0, 0); //Posición del renglón
    lcd.print("Voltaje CAS:"); //Mensaje
    lcd.setCursor(14 ,0); //Posición del cursor
    lcd.print(CAS); //Imprimir valor

    lcd.setCursor(0,1); //Posición del renglón
    lcd.print("Voltaje BE:"); //Mensaje
    lcd.setCursor(13,1); //Posición del cursor
    lcd.print(VBE); //Imprimir valor

    lcd.setCursor(0,2); //Posición del renglón
    lcd.print("Temp Celsius:"); //Mensaje
    lcd.setCursor(15,2); //Posición del cursor
    lcd.print(Celsius); //Imprimir valor

    lcd.setCursor(0,3); //Posición del renglón
    lcd.print("Temp Kelvin:"); //Mensaje
    lcd.setCursor(14,3); //Posición del cursor
    lcd.print(Kelvin); //Imprimir valor
    
    lcd.cursor();
    delay(500);
 }
