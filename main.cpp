#include <iostream>

#include "SerialBridge.h"
#include "Vehicle.h"
#include "TrackSession.h"
#include "Utils.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    Vehicle myCar(5000);
    TrackSession mySession("Spa");
    SerialBridge bridge;


    return 0;
}
