// Activity.h
#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <Arduino.h>

class Activity {
    public:
        String name;
        
        unsigned long int duration;
        float distance;
        
        boolean started;
        boolean paused;
        
        int speed_array[116];
        int altitude_array[116];
        int lat_array[116];
        int lon_array[116];

        // This method resets all attributes of the activity
        // and changes the activity name 
        void reset(String new_name){
            last_update_time = millis();
            started = false;
            paused = true;
            distance = 0;
            duration = 0;
            
            for (int i = 0; i < 116; i++) {
                speed_array[i] = 0;
                altitude_array[i] = 0;
                lat_array[i] = 0;
                lon_array[i] = 0;
            }
            name = new_name;
        }

        // This method writes the current activity to disk
        void write_activity(String name);

        // This method writes the latest data to disk
        void update_activity(String name);

        void pause_activity();

        void update(double speed){
            unsigned long int current_time = millis();
            unsigned long int delta_t = current_time - last_update_time;
            if (delta_t > 1000) delta_t = 0; /* Instead of this, implement a start/pause method  */
            last_update_time = current_time;

            distance += speed * delta_t / 1000;
            duration += delta_t;
        }

    private:
        unsigned long int last_update_time;

};

#endif // ACTIVITY_H