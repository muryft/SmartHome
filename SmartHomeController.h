#ifndef SMARTHOMECONTROLLER_H
#define SMARTHOMECONTROLLER_H

#include "SmartDevice.h"
#include "Light.h"
#include "Fan.h"
#include "Thermostat.h"

class SmartHomeController {
private:
    vector<SmartDevice*> devices;

public:
    void addDevice(SmartDevice* d) {
        if(findDevice(d->getId())){
            cout << "This ID is already exists"<< endl;
            return;
        }
        else
            devices.push_back(d);
    }

    void removeDevice(string id) {
        for (int i = 0; i < devices.size(); i++) {
            if (devices[i]->getId() == id) {
                devices.erase(devices.begin() + i);
                return;
            }
        }
    }

    SmartDevice* findDevice(string id) {
        for (int i = 0; i < devices.size(); i++)
            if (devices[i]->getId() == id)
                return devices[i];
        return NULL;
    }

    void turnOn(string id) {
        SmartDevice* d = findDevice(id);
        if (d) d->turnOn();
    }

    void turnOff(string id) {
        SmartDevice* d = findDevice(id);
        if (d) d->turnOff();
    }

    void showAll() const {
        if (devices.empty()) {
            cout << "No devices.\n";
            return;
        }
        for (int i = 0; i < devices.size(); i++)
            devices[i]->showStatus();
    }
};

#endif
