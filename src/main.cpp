#include <Arduino.h>
#include <GyverMAX7219.h>
MAX7219 < 4, 1, D6, D7, D8 > mtrx;
void runningString(String textToPrint){
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
  mtrx.begin();       // ?????????
  mtrx.setBright(2);  // ??????? 0..15
  mtrx.setScale(1);
  int x = 194;
  char y = x;
  // mtrx.println(y);
  mtrx.write(y);
  mtrx.update(); 
  Serial.begin(115200);
  //mtrx.setRotation(1);   // ????? ????????? 0..3, ?? 90 ???? ?? ??????? ???????
}

void loop() {
  // runingString("School number 12"); 
  // runningString("000qwe 00000 qwe"); 
  int x = '?';
  char y = x;
  Serial.println(y,DEC);
  //? 53655 A-144 ?-143
}