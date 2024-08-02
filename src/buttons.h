#include <Arduino.h>
#include <utils.h>

#define light_pin 13
extern unsigned long int light_on_time;

extern unsigned long int tlight, tscreensave, button_hold_time;

void light(){
  if (millis() - tlight > light_on_time) digitalWrite(light_pin, LOW);
  else digitalWrite(light_pin, HIGH);
}

button_status buttons(Bounce& L, Bounce& R, boolean& Lready, boolean& Rready){
    // The reason for & being used is that the input coming into this function is a reference to an existing
    // instance of Bounce, rather than a copy. While modifying this instance, we want those changes to be reflected
    // in the object being passed as argument to this function. Hence, we pass a reference to it rather than the object itself,
    // which would have created a copy and hence any modifications not being made visible during the operation of this function.
  R.update();
  L.update();
  unsigned long duration;

  if (R.read() == LOW && Rready == true){
    tlight = millis();
    tscreensave = millis();
    duration = R.currentDuration();
      if (duration > button_hold_time){
        Rready = false;
        return button_status{BUTTON_SELECT, 0};
      }
      else return button_status{HOLD_R, duration};
    }

  if (L.read() == LOW && Lready == true){
    tlight = millis();
    tscreensave = millis();
    duration = L.currentDuration(); 
      if (duration > button_hold_time){
        Lready = false;
        return button_status{BUTTON_BACK, 0};
      }
      else return button_status{HOLD_L, duration};
    }

  if (R.rose()){
    Rready = true;
    duration = R.previousDuration();
    if (duration < button_hold_time){
      return button_status{BUTTON_RIGHT, 0};
      }
    }

  if (L.rose()){
    Lready = true;
    duration = L.previousDuration();
    if (L.previousDuration() < button_hold_time){
      return button_status{BUTTON_LEFT, 0};
      }
    }

  return button_status{NO_BUTTON, 0};
}