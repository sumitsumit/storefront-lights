// storefront.ino - main arduino sketch for storefront lighting project
// note this won't compile if it's stored on OneDrive
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
  #include <math.h>
#endif

#define PIN 5
#define BRI 30
#define WIDTH 5
#define HEIGHT 10

// program
static int programnum = 0;
#define NUMPROGRAMS 2
// buttons
static int button1state = 0;


// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
// Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, PIN, NEO_RGB + NEO_KHZ400);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  Serial.begin(9600);
  pinMode(A0, INPUT);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}


void loop() {
  checkbuttons();
 if (programnum == 0) {
    allon(10);
  }
  if (programnum == 1) {
    alloff(10);
  }
}

void checkbuttons()
{
  // check button 2 - change animation
  int button1val = analogRead(A0);
  //Serial.println(button1val);
  if (button1val < 512 && button1state == 0)
  {
    // button 1 pressed brings the voltage low
    button1state = 1;

    // advance sequence
    programnum = (programnum + 1)%NUMPROGRAMS;
  }
  if (button1val > 512 && button1state == 1)
  {
    // button 1 released
    button1state = 0;
  }

}

void allon(uint8_t wait)
{
  for (uint16_t i=0; i < strip.numPixels(); i=i+1) {
    strip.setPixelColor(i,strip.Color(2*BRI,BRI,BRI));
  }

  strip.show();
  delay(wait);
}

void alloff(uint8_t wait)
{
  for (uint16_t i=0; i < strip.numPixels(); i=i+1) {
    strip.setPixelColor(i,strip.Color(0,0,0));
  }

  strip.show();
  delay(wait);
}

