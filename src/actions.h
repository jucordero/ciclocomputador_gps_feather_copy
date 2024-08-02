// actions.h
#ifndef ACTIONS_H
#define ACTIONS_H

#include <Arduino.h>
#include <RTCzero.h>
#include <utils.h>
#include <Activity.h>

#define GPSSerial Serial1

extern RTCZero rtc;
extern unsigned long int start_time, screensave_time;

extern int page1;
extern int idx;
extern Activity newActivity;

/**
 * Executes actions based on the current page of the application.
 * This function handles user input and updates the application state accordingly.
 * It supports the following pages:
 *
 * @param b The user input character to be processed.
 */
void actions(char b){
  // Executes actions based on the current page
  // ----------------------------main menu-------------------------------------
  switch (page1) {
    case PageState::SCREENSAVER:
      if (b != NO_BUTTON) {
        // wake up gps sending anything
        GPSSerial.print("\r\n");
        page1 = PageState::MAIN_MENU;
      }
      break;

    case PageState::MAIN_MENU:
      if (b == BUTTON_RIGHT) {
        idx = cycle_up(idx, 0, 4);
      }
      if (b == BUTTON_LEFT) {
        idx = cycle_down(idx, 0, 4);
      }
      if (b == BUTTON_SELECT) {
        switch (idx) {
          case 0:{
            page1 = PageState::NEW_ACTIVITY;
            idx = 0;
            String currentDate = String(rtc.getDay()) + "_" +
                                 String(rtc.getMonth()) + "_" +
                                 String(rtc.getHours()) + "_" +
                                 String(rtc.getMinutes());

            newActivity.reset(currentDate);
            break;
          }
          case 1:
            page1 = PageState::HISTORY;
            idx = 0;
            break;
          case 2:
            page1 = PageState::OPTIONS;
            idx = 0;
            break;
          case 3:
            page1 = PageState::DEBUG;
            idx = 0;
            break;
        }
      }
      break;

    case PageState::NEW_ACTIVITY:
      if (b == BUTTON_RIGHT) {
      }
      if (b == BUTTON_LEFT) {
      }
      if (b == BUTTON_SELECT) {
        // Start/pause activity
        newActivity.started = !newActivity.started;
      }
      if (b == BUTTON_BACK) {
        page1 = PageState::MAIN_MENU;
        idx=0;
      }
      break;

    case PageState::HISTORY:
      if (b == BUTTON_RIGHT) {
      }
      if (b == BUTTON_LEFT) {
      }
      if (b == BUTTON_SELECT) {
      }
      if (b == BUTTON_BACK) {
        page1 = PageState::MAIN_MENU;
        idx=1;
      }
      break;

    case PageState::OPTIONS:
      if (b == BUTTON_RIGHT) {
        idx = cycle_up(idx, 0, 4);
      }
      if (b == BUTTON_LEFT) {
        idx = cycle_down(idx, 0, 4);
      }
      if (b == BUTTON_SELECT) {
      }
      if (b == BUTTON_BACK) {
        page1 = PageState::MAIN_MENU;
        idx=2;
      }
      break;

    case PageState::DEBUG:
      if (b == BUTTON_RIGHT) {
        idx = cycle_up(idx, 0, 4);
      }
      if (b == BUTTON_LEFT) {
        idx = cycle_down(idx, 0, 4);
      }
      if (b == BUTTON_SELECT) {
        switch(idx){
          case 0:
            page1 = PageState::DEBUG_GPS;
            idx = 0;
            break;
          case 1:
            page1 = PageState::DEBUG_INPUTS;
            idx = 0;
            break;
          case 2:
            page1 = PageState::DEBUG_SCREEN;
            idx = 0;
            break;
          case 3:
            page1 = PageState::DEBUG_RTC;
            idx = 0;
            break;
        }
      }
      if (b == BUTTON_BACK) {
        page1 = PageState::MAIN_MENU;
        idx=3;
      }
      break;
    case PageState::DEBUG_GPS:
      if (b == BUTTON_RIGHT) {
      }
      if (b == BUTTON_LEFT) {
      }
      if (b == BUTTON_SELECT) {
      }
      if (b == BUTTON_BACK) {
        page1 = PageState::DEBUG;
        idx=0;
      }
      break;
    case PageState::DEBUG_INPUTS:
      if (b == BUTTON_RIGHT) {
      }
      if (b == BUTTON_LEFT) {
      }
      if (b == BUTTON_SELECT) {
      }
      if (b == BUTTON_BACK) {
        page1 = PageState::DEBUG;
        idx=1;
      }
      break;
    case PageState::DEBUG_SCREEN:
      if (b == BUTTON_RIGHT) {
      }
      if (b == BUTTON_LEFT) {
      }
      if (b == BUTTON_SELECT) {
      }
      if (b == BUTTON_BACK) {
        page1 = PageState::DEBUG;
        idx=2;
      }
      break;
    case PageState::DEBUG_RTC:
      if (b == BUTTON_RIGHT) {
      }
      if (b == BUTTON_LEFT) {
      }
      if (b == BUTTON_SELECT) {
      }
      if (b == BUTTON_BACK) {
        page1 = PageState::DEBUG;
        idx=3;
      }
      break;
  }
}

void screensave(){
  if (millis() - tscreensave > screensave_time && page1==PageState::MAIN_MENU){
    page1=PageState::SCREENSAVER;
    // Enter stand-by mode for power saving
    GPSSerial.print(F("$PMTK161,0*28\r\n"));
    }
}

#endif // ACTIONS_H