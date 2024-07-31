#include <Arduino.h>
#include <U8g2lib.h>
#include <TinyGPS++.h>
#include <RTCZero.h>
#include <Bounce2.h>

#include <draw.h>
#include <tracking.h>
#include <actions.h>
#include <buttons.h>
#include <utils.h>
#include <Activity.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define GPSSerial Serial1

// Real time clock and time related variables
RTCZero rtc;
byte hour, minute, second;
uint8_t day, month;
uint16_t year;

// GPS object and positional variables
TinyGPSPlus gps;
double speed;
int age;
int satellites;

// Activity
Activity newActivity;

// Display object
U8G2_UC1608_ERC240120_F_4W_HW_SPI u8g2(U8G2_R3, /* cs=*/ 10, /* dc=*/ 12, /* reset=*/ 11);
int page1 = 1;
int idx = 0;
unsigned long int timer, tlight, tscreensave;
int i_array = 0;
#define backlight_pin 13

// Input objects
int R_button = 14;
int L_button = 6;
Bounce debouncerR = Bounce();
Bounce debouncerL = Bounce();
button_status button_pressed = button_status{'n', 0};
boolean Lready = true;
boolean Rready = true;

void setup(void) {
  // Begin serial comunication with host and gps
  Serial.begin(9600);
  GPSSerial.begin(9600);

  // Initialize display
  u8g2.begin();
  u8g2_prepare();

  // Initialize clock
  rtc.begin();

  // Set pinmode for backlight
  pinMode(backlight_pin, OUTPUT);

  // Send anything to the module to wake it up just in case
  GPSSerial.print("\r\n");

  // Define gps module communication speed, data frequency and sleep mode 
  // GPSSerial.print(F("$PMTK251,9600*17\r\n"));
  // GPSSerial.print(F("$PMTK220,2000*1C\r\n"));
  // GPSSerial.print(F("$PMTK386,0.8*35\r\n"));
  // GPSSerial.print(F("$PMTK314,0,1,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*2C\r\n"));
  // GPSSerial.print(F("$PMTK314,-1*04\r\n"));

  // Set pin modes for input buttons
  pinMode(R_button, INPUT_PULLUP);
  pinMode(L_button, INPUT_PULLUP);

  // Initialize pin debouncers 
  debouncerR.attach(R_button);
  debouncerL.attach(L_button);
  debouncerR.interval(50);
  debouncerL.interval(50);
}

void loop(void) {
  // If a button is pressed, then we light the screen
  light();

  // Update gps status and positional data
  tracking();

  // Check buttons status and perform the corresponding actions
  button_pressed = buttons(debouncerL, debouncerR, Lready, Rready);
  actions(button_pressed.button);
  screensave();
  // Draw the current screen
  draw(button_pressed.button, button_pressed.duration);
}
