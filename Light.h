#ifndef LIGHT_H
#define LIGHT_H
#include "SmartDevice.h"

class Light : public SmartDevice {
public:
    Light(string id) : SmartDevice(id) {}

    void showStatus() const {
        cout << "Light [" << id << "] -> "
             << (isOn ? "ON" : "OFF") << endl;
    }
};

#endif
