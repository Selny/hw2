#include <iostream>

using namespace std;

class Car {
public:
    bool brake;
    bool accelerator;
    short fuel;
    Car() = default;
    Car(const bool brake, const bool accelerator, const short fuel) {
        this->brake = brake;
        this->accelerator = accelerator;
        this->fuel = fuel;
    }
    virtual void show() {};
    ~Car() {

    }
};

class Manual : public Car {
public:
    char manualTransmission;
    bool clutch;
    Manual() = default;
    Manual(const char manualTransmission, const bool brake, const bool accelerator, const bool clutch, const short fuel) : Car(brake, accelerator, fuel) {
        this->manualTransmission = manualTransmission;
        this->clutch = clutch;
    }
};
class Automatic : public Car {
public:
    char autoTransmission;
    float electric;
    Automatic() = default;
    Automatic(const char autoTransmission, const bool brake, const bool accelerator, const short fuel, const float electric) : Car(brake, accelerator, fuel) {
        this->autoTransmission = autoTransmission;
        this->electric = electric;
    }

    virtual void start() = 0;
};

class BMW : public Automatic {
public:
    bool autoLights;
    BMW() = default;
    BMW(const char autoTransmission, const bool brake, const bool accelerator, const float electric, const bool autoLights) : Automatic(autoTransmission, brake, accelerator, fuel, electric) {
        this->autoLights = autoLights;
    }

    void show() { cout << "This is BMW\n"; }
    virtual void start() { cout << "BMW Engine activated\n"; }
    void turbo() { cout << "Speed rised to 160\n"; }

};


class formula : public Automatic {
    int engineTemprature;
public:
    formula() = default;
    formula(const char autoTransmission, const bool brake, const bool accelerator, const float electric, const int engineTemprature) : Automatic(autoTransmission, brake, accelerator, fuel, electric) {
        this->engineTemprature = engineTemprature;
    }

    void show() { cout << "This is Formula\n"; }
    virtual void start() { cout << "Formula is activated\n"; }
    void emergencyBreak() { cout << "Warning car is damaged!"; }

};

class Mercedes : public Manual {
    int wheelDistance;
public:
    Mercedes() = default;
    Mercedes(const char manualTransmission, const bool brake, const bool accelerator, const bool clutch, const short fuel, const int wheelDistance)
        : Manual(manualTransmission, brake, accelerator, clutch, fuel) {
        this->wheelDistance = wheelDistance;
    }
    void show() { cout << "This is Mercedes\n"; }
    void drift() { cout << "Mercedes is drifting\n"; }
    void beep() { cout << "Beeep...\n"; }
};


void info(Car* other) {

    other->show();

}
int main() {

    Mercedes m('R', 0, 1, 1, 50, 30);
    formula f('A', 1, 1, 5.6, 90);
    BMW b('2', 0, 1, 10, 1);
    info(&m);
    info(&f);
    info(&b);
    return 0;
}
