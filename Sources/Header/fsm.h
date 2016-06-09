/** 
 * File:   fsm.h
 *
 * Class contains the controlling FSM for sorting out metal contaminated parts.
 * 
 * \author   Prof. Dr. Thomas Lehmann
 * \version  2
 * \date     2013-11-01
 * \modified 2016-05-09
 */

#ifndef FSM_H
#define	FSM_H

#include "FestoProcessSensors.h"
#include "FestoProcessActuators.h"
#include "plugin.h"
#include "HeightSensor.h"

enum fsm_states { Start, Standby, Ready, Transport, Reverse, Wait, MetalDetection, NonMetalic, Metalic, SlideReached, Error, EndReached};

class FSM {
private:
    fsm_states currentState;
    FestoProcessSensors *sensors;
    FestoProcessActuators *actuators;
    Plugin* plugin;
public:
    FSM( FestoProcessSensors *sensors, FestoProcessActuators *actuators, Plugin* plugin);
    ~FSM();
    void eval();
private:
    void evalEvents();
    void evalState();
private:
    void blinkGreen();
    void blinkRed();
};

#endif	/* FSM_H */

