
#include <cassert>
#include <iostream>

struct NightState {
    int hour = 12;
    int power = 100;
    bool leftDoor = false;
    bool rightDoor = false;
    bool camera = false;
    bool powerOut = false;

    void spendPower(int amount) {
        if (powerOut || amount <= 0) return;

        power -= amount;

        if (power <= 0) {
            power = 0;
            powerOut = true;
            leftDoor = false;
            rightDoor = false;
            camera = false;
        }
    }

    void tick() {
        if (powerOut) return;

        int drain = 1 + leftDoor
                      + rightDoor
                      + camera;

        spendPower(drain);
    }

    void nextHour() {
        if (hour == 12) hour = 1;
        else if (hour < 6) ++hour;
    }
};

int main() {
    NightState night;

    night.leftDoor = true;
    night.rightDoor = true;
    night.camera = true;
    night.tick();

    assert(night.power == 97);

    night.spendPower(97);
    assert(night.power == 0);
    assert(night.powerOut);
    assert(!night.leftDoor);
    assert(!night.rightDoor);
    assert(!night.camera);

    night.nextHour();
    assert(night.hour == 12);

    NightState clock;
    clock.nextHour();
    assert(clock.hour == 1);

    std::cout << "FNAF logic tests passed\n";
    return 0;
}
