/** 
 * File:   factory.h
 *
 * Service class setting up all objects of the system.
 * 
 * \author   Prof. Dr. Thomas Lehmann
 * \version  2
 * \date     2013-11-10
 * \modified 2016-05-09
*/

#ifndef FACTORY_H
#define FACTORY_H

#include "fsm.h"
#include "FestoProcessAccess.h"
#include "processimage.h"

class FSMFactory {
private:
    FestoProcessImage* image;
    FestoProcessAccess* access;
    FSM* stateMachine;
public:
    FSMFactory();
    virtual ~FSMFactory();
    FSM* createFSM();
};

#endif /* FACTORY_H */

