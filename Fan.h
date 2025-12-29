#ifndef FAN_H
#define FAN_H
#include "SmartDevice.h"

class Fan : public SmartDevice {
public:
    Fan(string id) : SmartDevice(id) {}

    void showStatus() const {
        cout << "Fan [" << id << "] -> "
             << (isOn ? "ON" : "OFF") << endl;
    }
};
#endif