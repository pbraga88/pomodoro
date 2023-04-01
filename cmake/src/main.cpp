#include <iostream>
#include <string>
#include <unistd.h> 
#include <map>
#include <ncurses.h>
#include <string.h>

#include "common.h"
#include "lcd.h"
#include "leds.h"
#include "speaker.h"
#include "ble.h"
#include "buttons.h"

void clean_input(int length) {

    // Move the cursor back to the start of the input
    move(0, length);

    // Overwrite the input with spaces
    for (int i = 0; i < length; i++) {
        addch(' ');
    }
    // Move the cursor back to the start of the input
    move(0, length);
    
}

state_type process_event(int sum_event_state) {
    state_type next_state = STATE_NULL;
    if (st_ev.find(sum_event_state) != st_ev.end()) {
        next_state = st_ev.at(sum_event_state);
    }

    return next_state;
}

int main() {
    // std::string input_command;
    const char* mode = modes.at(STATE_MODE_STUDY);

    // Create instances of the lcd, leds, speaker, BLE, and buttons
    LCD::lcd display;
    LEDS::leds ledsInterface;
    SPEAKER::speaker speakerBeep;
    BLE::ble bleModule;
    BUTTONS::buttons buttonsInterface;

    // Initialize lcd, leds, speaker, BLE, and buttons
    display.initialize((char*)mode);
    ledsInterface.intialize();
    speakerBeep.initialize();
    bleModule.initialize();
    buttonsInterface.initialize();

    initscr();  // Initialize ncurses
    
    debug("LCD mode", display.read());
    usleep(5000);
    // Initialize ncurses
    initscr();
    // Print a prompt and get user input
    // printw("LCD mode: %s \nPress B1 or B2: ", modes.at(STATE_MODE_STUDY));
    printw("LCD mode: %s \nPress B1 or B2: ", 
            display.read()==modes.at(STATE_MODE_STUDY) ? 
            "Study" : "Work");
    char event[256];
    getstr(event);

    while(true){
        if (strlen(event)) {
            if ((strcmp(event, "B1") == 0) &&
                (display.read() == modes.at(STATE_MODE_STUDY) ||
                 display.read() == modes.at(STATE_MODE_WORK))) {
                display.write((display.read() == modes.at(STATE_MODE_STUDY)) ?
                              (char*)modes.at(STATE_MODE_WORK) :
                              (char*)modes.at(STATE_MODE_STUDY));
                /*[...]*/
            }
            else if ((strcmp(event, "B2") == 0) &&
                    (display.read() == modes.at(STATE_MODE_STUDY) ||
                     display.read() == modes.at(STATE_MODE_WORK))) {
                display.write((display.read() == modes.at(STATE_MODE_STUDY)) ?
                              (char*)modes.at(STATE_STUDY_START) :
                              (char*)modes.at(STATE_WORK_START));
                /*[...]*/
            }
            // Clear the screen
            clear();
            printw("LCD mode: %s \nPress B1 or B2: ", display.read());
            // Refresh the screen to display the output
            refresh();
            memset(event, 0, strlen(event));
        }
        getstr(event);
        usleep(100);
    }

    // End ncurses
    endwin();

    return 0;
}
