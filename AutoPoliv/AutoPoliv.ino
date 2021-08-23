
#define _LCD_TYPE 1
#include <LCD_1602_RUS_ALL.h>
LCD_1602_RUS lcd(0x27, 16, 2);

#include <EncButton.h>
EncButton<EB_TICK, 2, 3, 4> enc;



#define rele 7

enum enumX
{
  nine= 9,
  fifteen = 15
};
enumX x=nine;

enum enumPutOrDelete
{
  _put = 0,
  _delete
};
enumPutOrDelete PutOrDelete = _put;

enum enumLines
{
  first = 0,
  second
};
enumLines line = first;

enum enumSides
{
  _left = 0,
  _right
};
enumSides side = _left;

void setup()
{
  Serial.begin(9600);
  enc.setHoldTimeout(3000);
  lcd.init();
  lcd.backlight();
  greetings();  
  lcd.clear();
  tunning();
}
void loop()
{

}

void type_of_typetable()
{
  lcd.setCursor(6, 0);
  lcd.print("TИП");
  lcd.setCursor(3, 1);
  lcd.print("PACПИCAHИЯ");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ИHTEPBAЛ");
  lcd.setCursor(0, 1);
  lcd.print("BЫБPAHHOE BPEMЯ");
  choose();
  lcd.clear();

}

void choose()
{
  Serial.print("Begin");
  put_or_delete_marker(_put, &line, _left,&x);
  while ((!enc.isHold()))
  { 
    enc.tick();
    if (enc.isClick())
    { 
      Serial.println("Click");
      put_or_delete_marker(_delete, &line, _left,&x);
      if (x==nine) x=fifteen; else x=nine;
      if (line==first) line=second; else line=first;
      put_or_delete_marker(_put, &line, _left,&x);      
    }   
    
  }
  Serial.println("Holded");
  lcd.clear();
}

void greetings()
{
  lcd.print("Добро пожаловать");
  delay(4000);
}

void tunning()
{
  type_of_typetable();
}

void  put_or_delete_marker(enumPutOrDelete PutOrDelete, enumLines *line, enumSides side, enumX *x)
{  
  lcd.setCursor(*x, *line);
  if (PutOrDelete == _put)
  {
    if (side == _left) 
    {
      lcd.print("<"); 
    }
    else lcd.print(">");
  }
  else lcd.print(" ");
}
