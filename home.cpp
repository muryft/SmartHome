#include <iostream>
#include <string>
#include <vector>
using namespace std;


class SmartDevice {
protected:
    string id;
    bool isOn;

public:
    SmartDevice(string id) : id(id), isOn(false) {}
    virtual ~SmartDevice() {}

    string getId() const { return id; }

    virtual void turnOn()  { isOn = true; }
    virtual void turnOff() { isOn = false; }

    virtual void showStatus() const = 0;
};


class Light : public SmartDevice {
public:
    Light(string id) : SmartDevice(id) {}

    void showStatus() const {
        cout << "Light [" << id << "] -> "
             << (isOn ? "ON" : "OFF") << endl;
    }
};

class Fan : public SmartDevice {
public:
    Fan(string id) : SmartDevice(id) {}

    void showStatus() const {
        cout << "Fan [" << id << "] -> "
             << (isOn ? "ON" : "OFF") << endl;
    }
};


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


class SmartHomeController {
private:
    vector<SmartDevice*> devices;

public:
    void addDevice(SmartDevice* d) {
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


int main() {
    SmartHomeController home;

    int choice;

    while (true) {
        cout << "\nSMART HOME MENU\n";
        cout << "1. Add Device\n";
        cout << "2. Turn ON Device\n";
        cout << "3. Turn OFF Device\n";
        cout << "4. Set Thermostat Temperature\n";
        cout << "5. Show All Devices\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 0)
            break;

        string id;
        int type;

        switch (choice) {
        case 1:
            cout << "Device type (1-Light, 2-Fan, 3-Thermostat): ";
            cin >> type;
            cout << "Device ID: ";
            cin >> id;

            if (type == 1)
                home.addDevice(new Light(id));
            else if (type == 2)
                home.addDevice(new Fan(id));
            else if (type == 3)
                home.addDevice(new Thermostat(id));
            else
                cout << "Invalid type!\n";
            break;

        case 2:
            cout << "Device ID to turn ON: ";
            cin >> id;
            home.turnOn(id);
            break;

        case 3:
            cout << "Device ID to turn OFF: ";
            cin >> id;
            home.turnOff(id);
            break;

        case 4:
            cout << "Thermostat ID: ";
            cin >> id;
            {
                SmartDevice* d = home.findDevice(id);
                Thermostat* t = dynamic_cast<Thermostat*>(d);
                if (t) {
                    int temp;
                    cout << "Enter temperature: ";
                    cin >> temp;
                    t->setTemperature(temp);
                } else {
                    cout << "Not a thermostat!\n";
                }
            }
            break;

        case 5:
            home.showAll();
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}