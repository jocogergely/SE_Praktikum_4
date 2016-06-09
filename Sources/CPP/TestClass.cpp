/* 
 * File:   TestClass.cpp
 * Author: abv861
 * 
 * Created on 1. Juni 2016, 14:36
 */

#include "TestClass.h"

TestClass::TestClass() {
}


TestClass::~TestClass() {
}


// datei öffen, einlsen
void TestClass::ReadTestData() {

}

bool TestClass::comp_sensor(bool sensorResult){
	return sampleError == sensorResult;
}


unsigned short TestClass::getHight(){
	string sample;
	getLine(sampleValues, sample);									//liest CSV-Datei zeilenweise ein
	string process_buffer = sample.substr(16, 4);					//extrahiert die Höhenwerte    
	current_sample = (unsigned short)strtoul(process_buffer);		//wandelt string->u_short
    return(current_sample);
};
