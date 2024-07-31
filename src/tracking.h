#include <Arduino.h>
#include <TinyGPS++.h>
#include <RTCZero.h>
#include <Activity.h>

#define GPSSerial Serial1

extern int age;
extern TinyGPSPlus gps;
extern byte hour, minute, second;
extern uint8_t day, month;
extern uint16_t year;
extern double distance;
extern double speed;
extern int satellites;
extern RTCZero rtc;
extern Activity newActivity;

void tracking(){
  while (GPSSerial.available() > 0) {
    char c = GPSSerial.read();
    // Serial.write(c);
    age = gps.speed.age();
    if (gps.encode(c)){
      hour = gps.time.hour();
      minute = gps.time.minute();
      second = gps.time.second();

      year = gps.date.year();
      month = gps.date.month();
      day = gps.date.day();

      // Update rtc
      rtc.setHours(hour);
      rtc.setMinutes(minute);
      rtc.setSeconds(second);

      rtc.setDay(day);
      rtc.setMonth(month);
      rtc.setYear(year - 2000);

      rtc.setEpoch(rtc.getEpoch()+3600);
      speed = gps.speed.mps();
      satellites = gps.satellites.value();
      }
    }
    if (newActivity.started) newActivity.update(speed);
  }