
#include <cassert>
#include <iostream>

struct NightState {
    int hour = 0;
    int energy = 100;
    bool leftDoor = false;
    bool rightDoor = false;
    bool cameraOpen = false;

    void toggleLeftDoor() {
        leftDoor = !leftDoor;
    }

    void toggleRightDoor() {
        rightDoor = !rightDoor;
    }

    void toggleCamera() {
        cameraOpen = !cameraOpen;
    }

    void advanceMinute() {
        if (hour < 6 && energy > 0) {
            --energy;
            if (energy < 0) energy = 0;
        }
    }
};

int main() {
    NightState night;

    night.toggleLeftDoor();
    assert(night.leftDoor);

    night.toggleRightDoor();
    assert(night.rightDoor);

    night.toggleCamera();
    assert(night.cameraOpen);

    night.advanceMinute();
    assert(night.energy == 99);

    std::cout << "FNAF logic tests passed\n";
    return 0;
}
