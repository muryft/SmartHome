#include <vector>
#include <iostream>
#include <string>
using namespace std;
#include "SmartHomeController.h"

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