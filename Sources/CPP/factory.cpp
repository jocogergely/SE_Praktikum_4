/** 
 * File:   factory.cpp
 *
 * Service class setting up all objects of the system.
 * 
 * \author  Prof. Dr. Thomas Lehmann
 * \version 1
 * \date    2013-11-10
 */

#include "factory.h"
#include "minilab1008processimage.h"

FSMFactory::FSMFactory() {
    image = NULL;
    access = NULL;
    stateMachine = NULL;
}

FSMFactory::~FSMFactory(){
    delete stateMachine;
    delete access;
    delete image;
}

FSM* FSMFactory::createFSM() {
    // Create Objects
    if (image == NULL) {
        image = new FestoMiniLab1008ProcessImage();
    }
    if ((access == NULL) && (image != NULL)) {
        access = new FestoProcessAccess(image);
    }
    if ((stateMachine == NULL) && (access != NULL)) {
        FestoProcessSensors* sens = access;
        FestoProcessActuators* act = access;

        //Plugin* plugin = new ...
        stateMachine = new FSM(sens, act, NULL);
    }
    return stateMachine;
}
