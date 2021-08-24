
#define _LCD_TYPE 1
#include <LCD_1602_RUS_ALL.h>
LCD_1602_RUS lcd(0x27, 16, 2);

#include <EncButton.h>
EncButton<EB_TICK, 3, 2, 4> enc;
#define rele 7
short minutes = 0;

enum enumX
{
  nine = 9,
  fifteen = 15
};
enumX x = nine;

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
  type_of_typetable();
  minutes = interval();
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
  choose(9, 15, &side);
  void resetState();
  lcd.clear();

}

void choose(int a, int b, enumSides *side)
{
  Serial.print("Begin");
  x == a;
  put_or_delete_marker(_put, &line, side, &x);
  while ((!enc.isHeld()))
  {
    enc.tick();
    if (enc.isClick())
    {
      Serial.println("Click");
      put_or_delete_marker(_delete, &line, side, &x);
      if (x == a) x = b; else x = a;
      if (line == first) line = second; else line = first;
      put_or_delete_marker(_put, &line, side, &x);
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

void  put_or_delete_marker(enumPutOrDelete PutOrDelete, enumLines *line, enumSides* side, enumX *x)
{
  lcd.setCursor(*x, *line);
  if (PutOrDelete == _put)
  {
    if (*side == _left)
    {
      lcd.print("<");
    }
    else lcd.print(">");
  }
  else lcd.print(" ");
}

int interval()
{
  Serial.println("beg");
  short minutes = 0;  
  bool change=false;
  lcd.setCursor(11, 0);
  lcd.print("минут");   
  lcd.setCursor(0, 1);
  lcd.print("=");
  lcd.setCursor(4, 1);
  lcd.print("час");
  lcd.setCursor(8, 1);
  lcd.print("и");
  lcd.setCursor(13, 1);
  lcd.print("мин");
  
  while ((!enc.isHeld()))
  {     
    enc.tick();
    if (change==true)
    {
      change=false;
      lcd.setCursor(0, 0); 
      lcd.print("    ");
      lcd.setCursor(1, 1); 
      lcd.print("  ");
      lcd.setCursor(10, 1); 
      lcd.print("  ");
    }
    lcd.setCursor(0, 0); 
    lcd.print(minutes, DEC);
    lcd.setCursor(1, 1);    
    lcd.print(minutes/60, DEC);
    lcd.setCursor(10, 1);    
    lcd.print(minutes%60, DEC);
    if (enc.isLeft())
    {
      if (minutes != 0)
      {
        minutes = minutes - 15;
        change=true;
      }
    }

    if (enc.isRight())
    {
      if (minutes != 1440)
      {
        minutes = minutes+15;
        change=true;
      }
    }
    if (enc.isLeftH()) 
    {      
      if (minutes >59)
      {
        minutes = minutes-60;
        change=true;
      }    
    }
    if (enc.isRightH())
    {
      
      if (minutes < 1381)
      {
        minutes = minutes+60;
        change=true;
      }    
    }
    
  }
  Serial.println("Holded");
  return minutes;
}
