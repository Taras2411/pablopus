#include <Arduino.h>
#include <GyverMAX7219.h>
MAX7219 < 4, 1, D6, D7, D8 > mtrx;
void runingString(String textToPrint){
  int length = strlen(textToPrint.c_str());\
  Serial.println(length);
  for(int i = 0; i<(length*5+length-1+31);i++){
    mtrx.setCursor(31-i,0);
    mtrx.println(textToPrint);
    mtrx.update(); 
    delay(80);
  }
  mtrx.clear();
}
void setup() {
  mtrx.begin();       // запускаем
  mtrx.setBright(2);  // яркость 0..15
  mtrx.setScale(1);

  Serial.begin(115200);
  //mtrx.setRotation(1);   // можно повернуть 0..3, по 90 град по часовой стрелке

  // mtrx.line(0, 0, 31, 7);  // (x0, y0, x1, y1)
  // mtrx.line(0, 7, 31, 0);
  // mtrx.setScale();
  // mtrx.setCursor(-5,0);
  // runingString("qwertyuiop");  
  // delay(1000);
  // mtrx.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  // runingString("School number 12"); 
  runingString("Привiт я їбанувася та пишу букву ґ та є "); 
}
