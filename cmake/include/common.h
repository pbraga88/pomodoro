#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <map>
#include <unordered_map>

template <typename t1, typename t2>
void debug(t1 func, t2 msg){
    std::cout<<func<<": "<<msg;
}

typedef enum {
    STATE_START=0,
    STATE_PWM_LED_01,
    STATE_PWM_LED_02,
    STATE_PWM_LED_03,
    STATE_PWM_LED_04,
    STATE_CYCLE_END,

    STATE_MODE_STUDY,
    STATE_MODE_WORK,

    STATE_STUDY_START,
    STATE_STUDY_ONGOING,
    STATE_STUDY_WAIT,

    STATE_WORK_START,
    STATE_WORK_ONGOING,
    STATE_WORK_WAIT,
    STATE_NULL,
} state_type;

typedef enum {
    EVENT_BUTTON_01,    // Change Mode
    EVENT_BUTTON_01_LP, //Long Press to Reset
    EVENT_BUTTON_02,    // Start/Stop
    EVENT_BLE,          // Bluetooth
    EVENT_TIMEOUT_01,     // 5'00
    EVENT_TIMEOUT_02,     // 10'00
    EVENT_TIMEOUT_03,     // 15'00
    EVENT_TIMEOUT_04,     // 20'00
    EVENT_TIMEOUT_05,     // 25'00
} event_type;

const std::map<int, const char*> modes {{STATE_MODE_STUDY, "Study"},
                                        {STATE_MODE_WORK, "Work"},
                                        {STATE_STUDY_START, "BlockNAvigation:StartCounter:StartPWMLED"},
                                        {STATE_STUDY_ONGOING, "Studying"},
                                        {STATE_STUDY_WAIT, "Study Paused"},
                                        {STATE_WORK_START, "BlockNAvigation:StartCounter:StartPWMLED"},
                                        {STATE_WORK_ONGOING, "Working"},
                                        {STATE_WORK_WAIT, "Work Paused"},
                                        };

const std::unordered_map<int, state_type> st_ev {{(EVENT_BUTTON_01<<8)|STATE_CYCLE_END, STATE_MODE_STUDY}, 
                                                 {(EVENT_BUTTON_01<<8)|STATE_MODE_STUDY, STATE_MODE_WORK},
                                                 {(EVENT_BUTTON_01<<8)|STATE_MODE_WORK, STATE_MODE_STUDY},
                                                 {(EVENT_BUTTON_01_LP<<8)|STATE_CYCLE_END, STATE_MODE_STUDY},
                                                 {(EVENT_BUTTON_01_LP<<8)|STATE_STUDY_ONGOING, STATE_MODE_STUDY},
                                                 {(EVENT_BUTTON_01_LP<<8)|STATE_STUDY_WAIT, STATE_MODE_STUDY},
                                                 {(EVENT_BUTTON_01_LP<<8)|STATE_WORK_ONGOING, STATE_MODE_WORK},
                                                 {(EVENT_BUTTON_01_LP<<8)|STATE_WORK_WAIT, STATE_MODE_WORK},
                                                 {(EVENT_BUTTON_02<<8)|STATE_CYCLE_END, STATE_MODE_STUDY},
                                                 {(EVENT_BUTTON_02<<8)|STATE_MODE_STUDY, STATE_STUDY_START},
                                                 {(EVENT_BUTTON_02<<8)|STATE_MODE_WORK, STATE_WORK_START},
                                                 {(EVENT_BUTTON_02<<8)|STATE_STUDY_ONGOING, STATE_STUDY_WAIT},
                                                 {(EVENT_BUTTON_02<<8)|STATE_STUDY_WAIT, STATE_STUDY_ONGOING},
                                                 {(EVENT_BUTTON_02<<8)|STATE_WORK_ONGOING, STATE_WORK_WAIT},
                                                 {(EVENT_BUTTON_02<<8)|STATE_WORK_WAIT, STATE_WORK_ONGOING},
                                                 {(EVENT_TIMEOUT_01<<8)|STATE_STUDY_ONGOING, STATE_PWM_LED_01},
                                                 {(EVENT_TIMEOUT_01<<8)|STATE_WORK_ONGOING, STATE_PWM_LED_01},
                                                 {(EVENT_TIMEOUT_02<<8)|STATE_STUDY_ONGOING, STATE_PWM_LED_02},
                                                 {(EVENT_TIMEOUT_02<<8)|STATE_WORK_ONGOING, STATE_PWM_LED_02},
                                                 {(EVENT_TIMEOUT_03<<8)|STATE_STUDY_ONGOING, STATE_PWM_LED_03},
                                                 {(EVENT_TIMEOUT_03<<8)|STATE_WORK_ONGOING, STATE_PWM_LED_03},
                                                 {(EVENT_TIMEOUT_04<<8)|STATE_STUDY_ONGOING, STATE_PWM_LED_04},
                                                 {(EVENT_TIMEOUT_04<<8)|STATE_WORK_ONGOING, STATE_PWM_LED_04},
                                                 {(EVENT_TIMEOUT_05<<8)|STATE_STUDY_ONGOING, STATE_CYCLE_END},
                                                 {(EVENT_TIMEOUT_04<<8)|STATE_WORK_ONGOING, STATE_CYCLE_END},
                                                 };

#endif