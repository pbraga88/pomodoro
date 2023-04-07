// interface.h
class Interface {
public:
    // Define a function pointer type for callbacks
    typedef void (*ButtonCallback)(bool);
    typedef void (*LEDCallback)(bool);

    // Register callbacks for the button and LED classes
    void registerButtonCallback(ButtonCallback callback);
    void registerLEDCallback(LEDCallback callback);

    // Call the registered button and LED callbacks
    void getButtonState(bool state);
    void setLEDState(bool state);
};

// button.h
class Button {
public:
    void init(Interface* interface);
    bool getButtonState();

private:
    Interface::ButtonCallback callback;
};

// button.cpp
void Button::init(Interface* interface) {
    // Register the getButtonState() callback with the interface class
    callback = std::bind(&Interface::getButtonState, interface, std::placeholders::_1);
    interface->registerButtonCallback(callback);
}

bool Button::getButtonState() {
    // Return the current state of the button
}

// led.h
class LED {
public:
    void init(Interface* interface);
    void setLEDState(bool state);

private:
    Interface::LEDCallback callback;
};

// led.cpp
void LED::init(Interface* interface) {
    // Register the setLEDState() callback with the interface class
    callback = std::bind(&Interface::setLEDState, interface, std::placeholders::_1);
    interface->registerLEDCallback(callback);
}

void LED::setLEDState(bool state) {
    // Set the state of the LED
}
