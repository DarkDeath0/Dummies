#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal LCD (rs, en, d4, d5, d6,  d7);
byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010,
};
byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
};

void setup() {
  LCD.begin(16, 2);
  LCD.createChar(0, armsDown);
  LCD.createChar(1, armsUp);
}

void loop() {
  for (int i = 7; i> -1; i--){
  if (i & 2 == 0){
  LCD.setCursor(i, 0);
  LCD.write(byte(1));
  LCD.setCursor(15 - i, 0);
  LCD.write(byte(1));
  delay(500);
  LCD.clear();
}
else{
LCD.setCursor(i, 0);
LCD.write(byte(0));
LCD.setCursor(15 - i, 0);
LCD.write(byte(0));
delay(500);
LCD.clear();
}
}
for (int i = 0; i < 8; i++){
  if (i % 2 == 0){
  LCD.setCursor(i, 1);
  LCD.write(byte(1));
  LCD.setCursor(15 - i, 1);
  LCD.write(byte(1));
  delay(500);
  LCD.clear();
}
else{
LCD.setCursor(i, 1);
LCD.write(byte(0));
LCD.setCursor(15 - i, 1);
LCD.write(byte(0));
delay (500);
LCD.clear();
}
}
}
