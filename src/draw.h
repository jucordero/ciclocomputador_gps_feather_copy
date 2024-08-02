// draw.h
#ifndef DRAW_H
#define DRAW_H

#include <Arduino.h>
#include <U8g2lib.h>
#include <RTCzero.h>
#include <bitmaps.h>
#include <utils.h>
#include <Activity.h>


extern U8G2_UC1608_ERC240120_F_4W_HW_SPI u8g2;
extern RTCZero rtc;
extern int satellites;
extern int age;
extern double speed;
extern int page1, idx;
extern unsigned long int tscreensave;
extern Activity newActivity;
extern uint16_t year;
extern double lat, lng;
extern unsigned long int button_hold_time, light_on_time, screensave_time;

void u8g2_prepare() {
  // Setup function: defines text mode and color 
  u8g2.setFontRefHeightExtendedText();
  u8g2.setDrawColor(1);
  u8g2.setFontPosTop();
  u8g2.setFontDirection(0);
}

/**
 * Returns the maximum value in the provided array, or 1 if the maximum is 0.
 *
 * @param v The array of 116 integer values.
 * @return The maximum value in the array, or 1 if the maximum is 0.
 */
int max_array(int v[]){
  int max = 0;
  for (int i = 0; i<116; i++){
    if(v[i] > max) max = v[i];
  }
  if (max == 0) return 1;
  return max;
}

/**
 * Draws two buttons on the screen, one on the left and one on the right.
 * The buttons can be filled based on the provided 'b' and 'd' values.
 *
 * @param b The button type, either 'i' for the left button or 'd' for the right button.
 * @param d The value to use for filling the button, between 0 and 1000.
 * @param left The text to display on the left button.
 * @param right The text to display on the right button.
 */
void draw_buttons(char b, long int d, const String left, const String right){
  int boxWidth = 60;
  int boxHeight = 20;
  int screenWidth = u8g2.getWidth();
  int screenHeight = u8g2.getHeight();
  int leftBoxX = 0;
  int rightBoxX = screenWidth - boxWidth;
  int boxY = screenHeight - boxHeight;

  // Draw left box
  u8g2.drawFrame(leftBoxX, boxY, boxWidth, boxHeight);
  u8g2.setFont(u8g2_font_6x10_tf);
  int textWidth = u8g2.getStrWidth(left.c_str());

  // Draw right box
  u8g2.drawFrame(rightBoxX, boxY, boxWidth, boxHeight);
  textWidth = u8g2.getStrWidth(right.c_str());

  // Fill boxes based on 'b' and 'd' values
  if (b == HOLD_L) {
    int fillWidth = map(d, 0, button_hold_time, 0, boxWidth - 2);
    u8g2.drawBox(leftBoxX + 1, boxY + 1, fillWidth, boxHeight - 2);
  } else if (b == HOLD_R) {
    int fillWidth = map(d, 0, button_hold_time, 0, boxWidth - 2);
    u8g2.drawBox(rightBoxX + 1, boxY + 1, fillWidth, boxHeight - 2);
  }
  u8g2.setFontMode(1);
  u8g2.setDrawColor(2);
  u8g2.drawStr(leftBoxX + (boxWidth - textWidth) / 2, boxY + 6, left.c_str());
  u8g2.drawStr(rightBoxX + (boxWidth - textWidth) / 2, boxY + 6, right.c_str());
}

/**
 * Draws the top bar of the GUI, displaying the current time, battery level,
 * and satellite information.
 * 
 * This function is responsible for rendering the top bar of the GUI, which includes
 * the current time, the battery level, and the number of satellites connected.
 * It also indicates if there has been no GPS update in the last 10 seconds.
 */
void draw_info(){
  u8g2.setFont(u8g2_font_crox2cb_mn);

  String hh = String(rtc.getHours());
  String mm = String(rtc.getMinutes());
  if (rtc.getMinutes() < 10) mm = '0' + mm;
  String hora = hh + ':' + mm;
  char buf[9];
  hora.toCharArray(buf, 9);
  u8g2.drawStr(1, -1, buf);

  int bat_level = (analogRead(A7) - 465)*20/170 ;
  u8g2.drawFrame(93, 2, 26, 13);
  u8g2.drawBox(95,4,bat_level,9);
  u8g2.drawBox(119,4,2,9);

  if (satellites > 0){
    for (int i = 0; i < satellites; i++){
      u8g2.drawVLine(55 + i*3, 13-i, i);
      u8g2.drawVLine(55 + i*3+1, 13-i, i);
    }
    // If no updates received in the last 10 seconds
    if (age > 10000){
      u8g2.setCursor(55+(satellites+1)*3, -1);
      u8g2.print(F("?"));
    }
  }
  else {
    u8g2.setCursor(55,-1);
    u8g2.print(F("No signal"));
  }
}

/**
 * Draws a graph of the provided array data.
 *
 * The input array must have a length of 116 elements.
 * The graph is drawn within a vertical line at x=2 and a horizontal line at y=y+h.
 * The height of each bar in the graph is proportional to the value in the corresponding
 * array element, scaled to fit within the provided height (h).
 *
 * @param y The y-coordinate of the top of the graph.
 * @param h The height of the graph.
 * @param v The array of 116 values to be graphed.
 */
void draw_graph(int y, int h, int v[]){
  
  u8g2.drawVLine(2, y, h);
  u8g2.drawHLine(2, y + h, 118);

  int vmax = max_array(v);
  for (int i = 0; i<116; i++){
    u8g2.drawVLine(i + 2, y + h - v[i]*h / vmax, (v[i] * h) / vmax);
  }
}


/**
 * Draws a selection list with the provided menu items.
 *
 * This function is responsible for rendering a selection list with the given menu items.
 * It sets the appropriate font, draws the corresponding frames and text for each menu item,
 * and highlights the currently selected item.
 *
 * @param items An array of String objects representing the menu items to be displayed.
 * @param itemCount The number of menu items in the items array.
 * @param selectedIndex The index of the currently selected menu item.
 */
void draw_selection_list(const String* items, int itemCount, int selectedIndex) {
  const int frameHeight = 20;
  const int frameWidth = 120;
  const int startY = 20;
  const int frameSeparation = 1;

  u8g2.setFont(u8g2_font_tenfatguys_tu);

  for (int i = 0; i < itemCount; i++) {
    int y = startY + i * (frameHeight + frameSeparation);
    
    if (i == selectedIndex) {
      u8g2.setDrawColor(1);
      u8g2.drawBox(0, y, frameWidth, frameHeight);
      u8g2.setDrawColor(0);
    } else {
      u8g2.setDrawColor(1);
    }

    u8g2.drawFrame(0, y, frameWidth, frameHeight);
    
    u8g2.setCursor(5, y + 5);
    u8g2.print(items[i]);

    u8g2.setDrawColor(1);
  }
}

/**
 * Draws the corresponding menus for the pages of the GUI.
 *
 * This function is responsible for rendering the different pages of the GUI.
 * It sets the appropriate font, draws the corresponding icons and text
 * for each page, and updates the display accordingly.
 *
 * @param page1 The index of the page to be drawn.
 */
void draw_page(int page1, int idx, char button, long int duration){
  // -----------------------------screensaver----------------------------------
  if (page1 == PageState::SCREENSAVER){
    String hh = String(rtc.getHours());
    String mm = String(rtc.getMinutes());
    if (rtc.getMinutes() < 10) mm = '0' + mm;
    if (rtc.getHours() < 10) hh = '0' + hh;

    u8g2.setFont(u8g2_font_fub49_tn);
    u8g2.setCursor(20, 60);
    u8g2.print(hh);

    u8g2.setCursor(20, 120);
    u8g2.print(mm);

    // Print day, month, and year in a smaller font
    u8g2.setFont(u8g2_font_profont12_tr);

    u8g2.setCursor(30, 180);
    u8g2.print(days_dict[calcDayOfWeek(rtc.getYear()+2000, rtc.getMonth(), rtc.getDay())]);

    String date = String(rtc.getDay())
      + "/" + months_dict[rtc.getMonth()]
      + "/" + String(rtc.getYear());
    u8g2.setCursor(30, 190);
    u8g2.print(date);

  }
  // -----------------------------main menu----------------------------------
  if (page1 == PageState::MAIN_MENU){
    String menuItems[] = {"NEW ACTIVITY", "HISTORY", "OPTIONS", "DEBUG"};
    draw_selection_list(menuItems, 4, idx);
    draw_buttons(button, duration, BACK, SELECT);
  }

  // -----------------------------new activity menu--------------------------
  if (page1 == PageState::NEW_ACTIVITY){

    u8g2.setFont(u8g2_font_tenfatguys_tu);
    u8g2.setCursor(30, 20);
    u8g2.print(F("SPEED"));

    u8g2.setCursor(15, 100);
    u8g2.print(F("DISTANCE"));

    u8g2.setCursor(35, 165);
    u8g2.print(F("TIME"));

    unsigned long int activity_time = newActivity.duration/1000;
    float activity_dist = newActivity.distance; 

    u8g2.setFont(u8g2_font_fub49_tn);
    if (3.6*speed < 10) u8g2.setCursor(20, 40);
    else u8g2.setCursor(40, 40);
    u8g2.print((int)(3.6*speed));
    u8g2.drawHLine(0, 95, 120);

    u8g2.setFont(u8g2_font_fub35_tn);
    if (activity_dist < 10) u8g2.setCursor(20, 120);
    else u8g2.setCursor(20, 120);
    u8g2.print(activity_dist/1000.0, 1);
    u8g2.drawHLine(0, 160, 120);

    u8g2.setFont(u8g2_font_fub20_tn);
    u8g2.setCursor(15, 180);
    u8g2.print(activity_time / 3600);
    u8g2.print(F(":"));
    if (activity_time % 3600 / 60 < 10) u8g2.print(F("0"));
    u8g2.print(activity_time % 3600 / 60);
    u8g2.print(F(":"));
    if (activity_time % 3600 % 60 < 10) u8g2.print(F("0"));
    u8g2.print(activity_time % 3600 % 60);

    if (newActivity.started == false) draw_buttons(button, duration, BACK, START);
    else draw_buttons(button, duration, BACK, PAUSE);
  }
  // ---------------------------- debug pages----------------------------
  if (page1 == PageState::DEBUG){
    
    String menuItems[] = {"GPS DATA", "INPUTS", "SCREEN", "RTC"};
    draw_selection_list(menuItems, 4, idx);
    draw_buttons(button, duration, BACK, SELECT);
  }
  
  if (page1 == PageState::DEBUG_GPS){
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.setCursor(0, 20);
    u8g2.print(F("GPS Data:"));

    u8g2.drawFrame(0, 30, 120, 70);
    u8g2.drawHLine(0, 45, 120);
    u8g2.drawVLine(60, 30, 60);

    u8g2.setCursor(5, 32);
    u8g2.print(F("Speed"));
    u8g2.setCursor(65, 32);
    u8g2.print(speed, 2);

    u8g2.setCursor(5, 47);
    u8g2.print(F("Lat"));
    u8g2.setCursor(65, 47);
    u8g2.print(lat, 2);

    u8g2.setCursor(5, 62);
    u8g2.print(F("Lon"));
    u8g2.setCursor(65, 62);
    u8g2.print(lng, 2);

    u8g2.setCursor(5, 77);
    u8g2.print(F("Sats"));
    u8g2.setCursor(65, 77);
    u8g2.print(satellites);

    draw_buttons(button, duration, BACK, SELECT);
  }
  if (page1 == PageState::DEBUG_INPUTS){
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.setCursor(0, 15);
    u8g2.print(F("Inputs:"));

    u8g2.drawFrame(0, 30, 120, 70);
    u8g2.drawHLine(0, 45, 120);
    u8g2.drawVLine(60, 30, 60);

    u8g2.setCursor(5, 32);
    u8g2.print(F("Hold"));
    u8g2.setCursor(65, 32);
    u8g2.print(button_hold_time);

    draw_buttons(button, duration, BACK, SELECT);
  }
  if (page1 == PageState::DEBUG_SCREEN){

    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.setCursor(0, 15);
    u8g2.print(F("Screen:"));

    u8g2.drawFrame(0, 30, 120, 70);
    u8g2.drawHLine(0, 45, 120);
    u8g2.drawVLine(60, 30, 60);

    u8g2.setCursor(5, 32);
    u8g2.print(F("Light"));
    u8g2.setCursor(65, 32);
    u8g2.print(light_on_time);

    u8g2.setCursor(5, 47);
    u8g2.print(F("Screensaver"));
    u8g2.setCursor(65, 47);
    u8g2.print(screensave_time);
    
    draw_buttons(button, duration, BACK, SELECT);
  }
  if (page1 == PageState::DEBUG_RTC){
    draw_buttons(button, duration, BACK, SELECT);
  }

  // -----------------------------options menu---------------------------
  if (page1 == PageState::OPTIONS){
    String menuItems[] = {"GPS SETTINGS", "SCREEN SETTINGS", "GUI SETTINGS"};
    draw_selection_list(menuItems, 3, idx);
    draw_buttons(button, duration, BACK, SELECT);
  }
// -----------------------------history menu---------------------------
  if (page1 == PageState::HISTORY){
    draw_buttons(button, duration, BACK, SELECT);
  }
}


/**
 * Draws the main display content, including information and the current page.
 * This function is responsible for clearing the display buffer, drawing the
 * necessary elements, and sending the updated buffer to the display.
 */
void draw(char button, long int duration){
  // Main draw function
  u8g2.clearBuffer();
  draw_info();
  draw_page(page1, idx, button, duration);
  u8g2.sendBuffer();
}

#endif // DRAW_H