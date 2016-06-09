/* 
 * File:   TestClass.h
 * Author: abv861
 *
 * Created on 1. Juni 2016, 14:36
 */

#ifndef TESTCLASS_H
#define	TESTCLASS_H

#include "FestoProcessSensors.h"

class TestClass : public FestoProcessSensors {

private:
	bool sampleError;
	FILE* sampleValues;
	unsigned short current_sample;
    
public:
    TestClass();
    ~TestClass();
    
    virtual unsigned short getHight();		//benutzt ReadTestData, um Testwerte zu liefern, wandelt string der CSV in u_int um
    bool comp_sensor(bool sensorResult);	//vergleicht von HeightSensor geliefertes result() mit bekannten Werten

private:
    void ReadTestData(FILE* sampleValues); 	// datei öffen, einlesen

};

#endif	/* TESTCLASS_H */

