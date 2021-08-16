#define _LCD_TYPE 1
#include <LCD_1602_RUS_ALL.h>
LCD_1602_RUS <LiquidCrystal_I2C> lcd(0x27, 16, 2);
#define rele 7
void setup()
{ 
  lcd.init();
  lcd.backlight();
  lcd.print("Добро пожаловать");
  delay(5000);
  lcd.clear();
  tuning();
}
void loop() 
{
        
}          

void tuning() 
{ 
  lcd.setCursor(1,0);
  lcd.print(" ");
    lcd.setCursor(1,1);
    lcd.print(" ");  
  lcd.setCursor(1,0);
  lcd.print("T");
    lcd.setCursor(1,1);
    lcd.print("И");  
  lcd.setCursor(2,0);
  lcd.print("И");
    lcd.setCursor(2,1);
    lcd.print("H");  
  lcd.setCursor(3,0);
  lcd.print("П");
    lcd.setCursor(3,1);
    lcd.print("T");
  lcd.setCursor(4,0);
  lcd.print(" ");
    lcd.setCursor(4,1);
    lcd.print("E");
  lcd.setCursor(5,0);
  lcd.print("P");
    lcd.setCursor(5,1);
    lcd.print("P");  
  lcd.setCursor(6,0);
  lcd.print("A");
    lcd.setCursor(6,1);
    lcd.print("B");  
  lcd.setCursor(7,0);
  lcd.print("C");
    lcd.setCursor(7,1);
    lcd.print("A");  
  lcd.setCursor(8,0);
  lcd.print("П");
    lcd.setCursor(8,1);
    lcd.print("Л");  
  lcd.setCursor(9,0);
  lcd.print("И");
    lcd.setCursor(9,1);
    lcd.print("");  
  lcd.setCursor(10,0);
  lcd.print("C");
    lcd.setCursor(10,1);
    lcd.print("B");  
  lcd.setCursor(11,0);
  lcd.print("A");
    lcd.setCursor(11,1);
    lcd.print("P");  
  lcd.setCursor(12,0);
  lcd.print("H");
    lcd.setCursor(12,1);
    lcd.print("E");
  lcd.setCursor(13,0);
  lcd.print("И");
    lcd.setCursor(13,1);
    lcd.print("M");  
  lcd.setCursor(14,0);
  lcd.print("Я");
    lcd.setCursor(14,1);
    lcd.print("Я");
  lcd.setCursor(15,0);
  lcd.print(" ");
    lcd.setCursor(15,1);
    lcd.print(" ");
}

void choose() 
{
        
}  
