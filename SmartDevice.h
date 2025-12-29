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

