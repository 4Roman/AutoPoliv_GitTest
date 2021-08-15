#define rele 7
void setup() 
{ 
  pinMode(rele, OUTPUT);
}

void loop() 
{
  delay(3000);
  digitalWrite(rele, HIGH);   // переключвет
  delay(3000);                      
  digitalWrite(rele, LOW);    // Возвращает в исходное состояние
  delay(28800000);                      
} 
