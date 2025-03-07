#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX_AS.h>
#include <Adafruit_SSD1306_STM32.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
// put function declarations here:

void testdrawchar(void) {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  for (uint8_t i=0; i < 168; i++) {
    if (i == '\n') continue;
    display.write(i);
    if ((i > 0) && (i % 21 == 0))
      display.println();
  }    
  display.display();
}

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  display.display();
  testdrawchar();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
