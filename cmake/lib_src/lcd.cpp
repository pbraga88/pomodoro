#include "lcd.h"
#include "common.h"

namespace LCD {
    lcd::lcd(){
    }
    lcd::~lcd(){
    }


    void lcd::initialize(char* init_msg){
        /* Initialize LCD object with default mode message */
        this->lcd_message = init_msg;
        
        debug("LCD", "Initialized\n");
        /* INITIALIZATION ROUTINES */
        //[...]
    }

    void lcd::write(char* input_msg) {
        /* Update LCD */
        this->lcd_message = input_msg;
    }

    char* lcd::read() {
        return lcd_message;
    }
}