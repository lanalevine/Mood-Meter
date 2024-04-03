// left - 5v, middle 36, right g

#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI(); 
String voltString;
String tempTimeString;
float voltConverted;
int mood = 0;
float angry = 0;
float sad = 0;
float fine = 0;
float happy = 0;
float excited = 0;
float total = 0;
float calcAngry;
float calcSad;
float calcFine;
float calcHappy;
float calcExcited;

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);



}

// the loop routine runs over and over again forever:
void loop() {
  
  // SERIAL MONITOR
  
  // read the input on analog pin GPIO36:
  int analogValue = analogRead(36);
  // Rescale to potentiometer's voltage (from 0V to 3.3V):
  float voltage = floatMap(analogValue, 0, 4095, 0, 3.3);

  // print out the value you read:
  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(", Voltage: ");
  Serial.println(voltage);
  tft.setTextSize(1);

//convert volt

// sad angry fine happy excited

  if((voltage/3.3)<.2){
    mood = 5; // excited
    excited++;
  }
  else if((voltage/3.3)<.4){
  mood = 4; //happy
  happy++;
  }
  else if((voltage/3.3)<.6){
  mood = 3; //fine
  fine++;
}
else if((voltage/3.3)<.8){
  mood = 1; //sad
  sad++;
}
else {
  mood = 2; //angry
  angry++;
}

total = (angry+sad+fine+happy+excited);


// SCREEN

 switch(mood){

  case 1:
  Serial.println("sad");
  
  // sad
  tft.fillScreen(TFT_BLUE);
  tft.fillCircle(102, 40, 10, TFT_BLACK);
  tft.fillCircle(138, 40, 10, TFT_BLACK);
  tft.drawArc(120, 95, 30, 23, 90, 270, TFT_BLACK, TFT_BLACK);
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  tft.drawString("sad", 92, 105);

  delay(2000);

  tft.setTextSize(2);

  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_RED);
  tft.drawString("You are angry " + String(((angry/total)* 100)) + "%", 10, 10);
  tft.setTextColor(TFT_BLUE);
  tft.drawString("You are sad " + String((100*(sad/total))) + "%", 10, 30);
  tft.setTextColor(TFT_BLACK);
  tft.drawString("You are fine " + String((100*(fine/total))) + "%", 10, 50);
  tft.setTextColor(TFT_GREEN);
  tft.drawString("You are happy " + String((100*(happy/total))) + "%", 10, 70);
  tft.setTextColor(TFT_YELLOW);
  tft.drawString("You are excited " + String((100*(excited/total))) + "%", 10, 90);


  break;
  
  case 2:
  Serial.println("angry");
  
  // draw angry
  tft.fillScreen(TFT_RED);
  tft.fillCircle(102, 40, 10, TFT_BLACK);
  tft.fillCircle(138, 40, 10, TFT_BLACK);
  tft.drawArc(120, 95, 30, 0, 90,270, TFT_BLACK, TFT_BLACK);
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  tft.drawString("angry", 78, 105);

  delay(2000);

  tft.setTextSize(2);

  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_RED);
  tft.drawString("You are angry " + String(((angry/total)* 100)) + "%", 10, 10);
  tft.setTextColor(TFT_BLUE);
  tft.drawString("You are sad " + String((100*(sad/total))) + "%", 10, 30);
  tft.setTextColor(TFT_BLACK);
  tft.drawString("You are fine " + String((100*(fine/total))) + "%", 10, 50);
  tft.setTextColor(TFT_GREEN);
  tft.drawString("You are happy " + String((100*(happy/total))) + "%", 10, 70);
  tft.setTextColor(TFT_YELLOW);
  tft.drawString("You are excited " + String((100*(excited/total))) + "%", 10, 90);


  break;
  
  case 3:
  Serial.println("fine");
  
  // draw fine
  tft.fillScreen(TFT_WHITE);
  tft.fillCircle(102, 40, 10, TFT_BLACK);
  tft.fillCircle(138, 40, 10, TFT_BLACK);
  tft.fillCircle(122, 73, 10, TFT_BLACK);
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  tft.drawString("fine", 83, 105);


  delay(2000);

  tft.setTextSize(2);

  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_RED);
  tft.drawString("You are angry " + String(((angry/total)* 100)) + "%", 10, 10);
  tft.setTextColor(TFT_BLUE);
  tft.drawString("You are sad " + String((100*(sad/total))) + "%", 10, 30);
  tft.setTextColor(TFT_BLACK);
  tft.drawString("You are fine " + String((100*(fine/total))) + "%", 10, 50);
  tft.setTextColor(TFT_GREEN);
  tft.drawString("You are happy " + String((100*(happy/total))) + "%", 10, 70);
  tft.setTextColor(TFT_YELLOW);
  tft.drawString("You are excited " + String((100*(excited/total))) + "%", 10, 90);


  break;
  
  case 4:
  Serial.println("Happy");
  
  // draw smiley
  tft.fillScreen(TFT_GREEN);
  tft.fillCircle(102, 40, 10, TFT_BLACK);
  tft.fillCircle(138, 40, 10, TFT_BLACK);
  tft.drawArc(120, 70, 30, 23, 270,90, TFT_BLACK, TFT_BLACK);
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  tft.drawString("happy", 77, 105);


  delay(2000);

  tft.setTextSize(2);

  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_RED);
  tft.drawString("You are angry " + String(((angry/total)* 100)) + "%", 10, 10);
  tft.setTextColor(TFT_BLUE);
  tft.drawString("You are sad " + String((100*(sad/total))) + "%", 10, 30);
  tft.setTextColor(TFT_BLACK);
  tft.drawString("You are fine " + String((100*(fine/total))) + "%", 10, 50);
  tft.setTextColor(TFT_GREEN);
  tft.drawString("You are happy " + String((100*(happy/total))) + "%", 10, 70);
  tft.setTextColor(TFT_YELLOW);
  tft.drawString("You are excited " + String((100*(excited/total))) + "%", 10, 90);

  break;

  case 5:
  Serial.println("excited");
  
  // draw smiley
  tft.fillScreen(TFT_YELLOW);
  tft.fillCircle(102, 40, 10, TFT_BLACK);
  tft.fillCircle(138, 40, 10, TFT_BLACK);
  tft.drawArc(120, 70, 30, 0, 270,90, TFT_BLACK, TFT_BLACK);
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3);
  tft.drawString("excited", 60, 105);


  delay(2000);

  tft.setTextSize(2);


  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_RED);
  tft.drawString("You are angry " + String(((angry/total)* 100)) + "%", 10, 10);
  tft.setTextColor(TFT_BLUE);
  tft.drawString("You are sad " + String((100*(sad/total))) + "%", 10, 30);
  tft.setTextColor(TFT_BLACK);
  tft.drawString("You are fine " + String((100*(fine/total))) + "%", 10, 50);
  tft.setTextColor(TFT_GREEN);
  tft.drawString("You are happy " + String((100*(happy/total))) + "%", 10, 70);
  tft.setTextColor(TFT_YELLOW);
  tft.drawString("You are excited " + String((100*(excited/total))) + "%", 10, 90);

  break;

 }

  


//delay
delay(2000);
}