#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"

class Thermostat : public SmartDevice {
private:
    int temperature;

public:
    Thermostat(string id, int temp = 22)
        : SmartDevice(id), temperature(temp) {}

    void setTemperature(int t) { temperature = t; }

    void showStatus() const {
        cout << "Thermostat [" << id << "] -> "
             << (isOn ? "ON" : "OFF")
             << ", Temperature: " << temperature << endl;
    }
};
#endif