/** 
 * File:   fsm.cpp
 *
 * Class contains the controlling FSM for sorting out metal contaminated parts.
 * 
 * \author  Prof. Dr. Thomas Lehmann
 * \version 1
 * \date    2013-11-01
 */

#include "fsm.h"
FSM::FSM( FestoProcessSensors *sensors, FestoProcessActuators *actuators, Plugin* plugin = 0){
    this->sensors = sensors;
    this->actuators = actuators;
    this->plugin = plugin;

    currentState = Start;
}

FSM::~FSM() {
}

void FSM::eval() {
    sensors->updateInputs();
    if (plugin != NULL) {
        plugin->evalCycle();
    }
    evalEvents();
    evalState();
    actuators->applyOutput();
}

void FSM::evalEvents() {
    switch (currentState) {
        case Start:
            currentState = Standby;
            break;
        case Standby:
            if (sensors->isButtonStartNegativeEdge()) {
                currentState = Ready;
            }
            break;
        case Ready:
            if (sensors->isButtonStartNegativeEdge()) {
                currentState = Standby;
            }
            if (sensors->isItemAtBeginning()&& !sensors->isItemAtEnd()) {
                currentState = Transport;
            }
            if (sensors->isItemAtHightSensor() || sensors->isItemAtMetalDetector()) {
                currentState = Error;
            }
            break;
        case Transport:
            if (plugin->result()){
                currentState = Reverse;
            }
            if (sensors->isItemAtMetalDetector()) {
                currentState = MetalDetection;
            }
            if (sensors->isItemAtEnd()) {
                currentState = Error;
            }
            break;
        case Reverse:
            if(sensors->isItemAtBeginning()){
                currentState = Wait;
            }
            break;
        case Wait:
            if (!sensors->isItemAtBeginning()){
                currentState = Ready;
            }
            break;
        case MetalDetection:
            if (sensors->isMetalDetected()) {
                currentState = Metalic;
            } else {
                currentState = NonMetalic;
            }
            break;
        case NonMetalic:
            if (sensors->isItemAtEnd()) {
                currentState = EndReached;
            }
            if (sensors->isItemAtBeginning() || sensors->isItemAtHightSensor()) {
                currentState = Error;
            }
            break;
        case EndReached:
            if (sensors->isButtonStartNegativeEdge()) {
                currentState = Standby;
            }
            if (!(sensors->isItemAtEnd())) {
                currentState = Ready;
            }
            if (sensors->isItemAtMetalDetector() || sensors->isItemAtHightSensor()) {
                currentState = Error;
            }
            break;
        case Metalic:
            if (sensors->hasItemPassedSlide()) {
                currentState = SlideReached;
            }
            if (sensors->isItemAtBeginning() || sensors->isItemAtHightSensor()) {
                currentState = Error;
            }
            break;
        case SlideReached:
            if (sensors->isButtonStartNegativeEdge()) {
                currentState = Standby;
            }
            if (sensors->isItemAtBeginning()) {
                currentState = Transport;
            }
            if (sensors->isItemAtEnd() || sensors->isItemAtHightSensor()) {
                currentState = Error;
            }
            break;
        case Error:
            if (sensors->isButtonStartNegativeEdge()) {
                currentState = Standby;
            }
            break;
        default:
            currentState = Start;
    }
}

void FSM::evalState() {
    switch (currentState) {
        case Start:
        case Standby:
            actuators->driveStop();
            actuators->lightGreenOff();
            actuators->lightRedOff();
            actuators->lightYellowOff();
            actuators->turnLEDQ1Off();
            actuators->turnLEDQ2Off();
            actuators->turnLEDResetOff();
            actuators->turnLEDStartOn();
            break;
        case Ready:
            actuators->driveStop();
            actuators->lightGreenOn();
            actuators->lightRedOff();
            actuators->lightYellowOff();
            actuators->turnLEDStartOn();
            break;
        case Transport:
            actuators->driveRight();
            actuators->lightGreenOn();
            actuators->lightRedOff();
            actuators->lightYellowOff();
            actuators->turnLEDStartOff();
            break;
        case Reverse:
            blinkRed();
            actuators->lightGreenOff();
            actuators->driveStop();
            actuators->driveLeft();
            break;
        case Wait:
            actuators->driveStop();
            actuators->lightRedOn();
            break;
        case MetalDetection:
            actuators->driveStop();
            actuators->lightGreenOn();
            actuators->lightRedOff();
            actuators->lightYellowOff();
            break;
        case NonMetalic:
            actuators->driveRight();
            actuators->lightGreenOn();
            actuators->lightRedOff();
            actuators->lightYellowOff();
            actuators->turnLEDStartOff();
            actuators->openJunction();
            break;
        case EndReached:
            actuators->driveStop();
            actuators->lightRedOff();
            actuators->lightYellowOff();
            actuators->turnLEDStartOff();
            actuators->closeJunction();
            actuators->turnLEDStartOn();
            blinkGreen();
            break;
        case Metalic:
            actuators->driveRight();
            actuators->lightGreenOff();
            actuators->lightRedOff();
            actuators->lightYellowOn();
            break;
        case SlideReached:
            actuators->driveStop();
            actuators->lightGreenOn();
            actuators->lightRedOff();
            actuators->lightYellowOff();
            actuators->turnLEDStartOn();
            break;
        case Error:
            actuators->driveStop();
            actuators->lightGreenOff();
            actuators->lightYellowOff();
            actuators->turnLEDStartOn();
            actuators->closeJunction();
            blinkRed();
            break;

    }
}

void FSM::blinkRed() {
    if (sensors->timeCounter1s() & 0x01) {
        actuators->lightRedOn();
    } else {
        actuators->lightRedOff();
    }
}

void FSM::blinkGreen() {
    if (sensors->timeCounter1s() & 0x01) {
        actuators->lightGreenOn();
    } else {
        actuators->lightGreenOff();
    }
}
