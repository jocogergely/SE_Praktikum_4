
#include <iostream>
#include "HeightSensor.h"
using namespace std;
void HeightSensor::evalCycle() {

    //speichert krams in die privaten variablen
}

bool HeightSensor::result() {
    bool ItemOk = 1;


    for (int i = 0; (i <= 10)&&(ItemOk); i++) {
        //Vergleich
        if (this->MusterOk[i] != this->MusterMessure[i]) {
            ItemOk = false;

            if (i == 3) {
                cout << "FehlerMuster 1";
            } else if (i == 4) {
                cout << "FehlerMuster 2";
            }
        }
    }
    //return (ist alles okiedokiekie?)
    // vergleicht das Array der gemessen werte mit den hinterlgeten
    return (ItemOk);
}