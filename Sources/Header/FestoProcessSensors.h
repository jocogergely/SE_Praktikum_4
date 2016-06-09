/** 
 * File:   FestoSensors.h
 * 
 * Interface defining high-level access to sensors of the FESTO system.
 * 
 * \author   Prof. Dr. Thomas Lehmann
 * \version  2
 * \date     2013-11-08
 * \modified 2016-05-09
*/

#ifndef FESTOSENSORS_H
#define	FESTOSENSORS_H
#include "time.h"

class FestoProcessSensors {
public:
    virtual ~FestoProcessSensors(){};
    virtual bool isItemAtBeginning(void) = 0;
    virtual bool isItemAtHightSensor(void) = 0;
    virtual bool isItemAtMetalDetector(void) = 0;
    virtual bool isMetalDetected(void) = 0;
    virtual bool isJunctionOpen(void) = 0;
    virtual bool isItemAtSlide(void) = 0;
    virtual bool hasItemPassedSlide(void) = 0;
    virtual bool isItemAtEnd(void) = 0;
    virtual bool isButtonStartPressed(void) = 0;
    virtual bool isButtonStartPositiveEdge(void) = 0;
    virtual bool isButtonStartNegativeEdge(void) = 0;
    virtual bool isButtonStopPressed(void) = 0;
    virtual bool isButtonResetPressed(void) = 0;
    virtual bool isButtonEmergencyActive(void) = 0;
    virtual unsigned short getHight() = 0;

    virtual time_t timeCounter1s() = 0;
    virtual void updateInputs(void) = 0;
};

#endif	/* FESTOSENSORS_H */

