#ifndef LCD_H
#define LCD_H

#include <iostream>
#include <string>
#include <string_view>

namespace LCD {

    class lcd {
        char* lcd_message;

    public:
        lcd();
        ~lcd();

        void initialize(char* init_msg);
        void write(char* input_msg);
        char* read();
    };
}
#endif