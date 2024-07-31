// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>
#include <map>

std::map<int, const String> months_dict = {
    { 1, "January" },
    { 2, "February" },
    { 3, "March" },
    { 4, "April" },
    { 5, "May" },
    { 6, "June" },
    { 7, "July" },
    { 8, "August" },
    { 9, "September" },
    { 10, "October" },
    { 11, "November" },
    { 12, "December" }
};

std::map<int, const String> days_dict = {    
    { 0, "Monday" },
    { 1, "Tuesday" },
    { 2, "Wednesday" },
    { 3, "Thursday" },
    { 4, "Friday" },
    { 5, "Saturday" },
    { 6, "Sunday" },
};



struct button_status{
    char button;
    long int duration;
};

enum PageState {
    SCREENSAVER=0,
    MAIN_MENU=1,
    NEW_ACTIVITY=11,
    HISTORY=22,
    OPTIONS=33,
    DEBUG=44
};

const String BACK = "BACK";
const String START= "START";
const String SELECT= "SELECT";
const String PAUSE= "PAUSE";

const char BUTTON_RIGHT = 'r';
const char BUTTON_LEFT = 'l';
const char BUTTON_SELECT = 'R';
const char BUTTON_BACK = 'L';
const char NO_BUTTON = 'n';
const char HOLD_R = 'd';
const char HOLD_L = 'i';

/**
 * Cycles the given index up within the specified range.
 *
 * @param idx The current index to cycle up.
 * @param low The lower bound of the range (inclusive).
 * @param high The upper bound of the range (exclusive).
 * @return The new cycled up index.
 */
int cycle_up(int idx, int min, int max){
    idx++;
    if (idx == max) idx = min; 
    return idx;
}

/**
 * Cycles the given index down within the specified range.
 *
 * @param idx The current index to cycle down.
 * @param low The lower bound of the range (inclusive).
 * @param high The upper bound of the range (exclusive).
 * @return The new cycled down index.
 */
int cycle_down(int idx, int min, int max){
    idx--;
    if (idx < min) idx = max-1;
    return idx;
}

byte calcDayOfWeek(unsigned int y, byte m, byte d) 
{
  // cast out multiples of 400 from y
  y -= (2000 * (y >> 11));
  while (y >= 400) y -= 400;

  boolean leap = ((y & 3) == 0);
  if ((y == 100) || (y == 200) || (y == 300)) leap = false;

  if (d > 31 || d == 0) return 0; 

  byte w = 6;
  while (y >= 100) {y -= 100; w -= 2; }

  w += (y + (y >> 2));

  // correction for Jan. and Feb. of leap year
  if (leap && (m <= 2)) w--;

  // using subtraction iso addition makes the while at end possible 1 iteration faster.
  switch (m) 
  {
  case 1: 
    w++; 
    break;
  case 2:  
    if (d > (leap ? 29 : 28)) return 0; 
    w += 4; 
    break;
  case 3:
    w += 4; 
    break;
  case 5:  
    w += 2; 
    break;
  case 7:
    break;
  case 8:  
    w += 3; 
    break;
  case 10:
    w++; 
    break;
  case 12:
    w += 6; 
    break;
  default:
    if (d > 30) return 0; 
    switch (m) 
    {
    case 4:  
      break;
    case 6:  
      w += 5; 
      break;
    case 9:  
      w += 6; 
      break;
    case 11:  
      w += 4; 
      break;
    default:
      return 0;
    }
  }
  
  w += d;

  // there are only 7 days in a week, so we "cast out" sevens
  while (w > 7) w = (w >> 3) + (w & 7);
  return w;
}

#endif // UTILS_H