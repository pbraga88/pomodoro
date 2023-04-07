#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include "lcd.h"
class Interface {
public:
    // Define a function pointer type for callbacks
    typedef void (*LCDCallback)(void);

    // Register callback for LCD
    void registerLCDCallback(LCDCallback callback);

    // Call the registered LCD callback
    void initializeLCD(void);
};


#endif
