#ifndef LCD_H
#define LCD_H

#include <iostream>
#include <string>
#include <string_view>
#include "interface.h"

namespace LCD {

    class lcd {
        char* lcd_message;

    public:
        lcd();
        ~lcd();

        // To register callback
        void callback_init(Interface* interface);

        void initialize(char* init_msg);
        void write(char* input_msg);
        char* read();
    };
}
#endif