/* 
 * File:   HeightSensor.h
 * Author: abv861
 *
 * Created on 1. Juni 2016, 13:51
 */

#ifndef HEIGHTSENSOR_H
#define	HEIGHTSENSOR_H

#include "plugin.h"



class HeightSensor: public Plugin{
private:
    int MusterOk[6]={1,2,1,2,3,1};
    int MusterFalse1[6]={1,2,1,3,2,1};
    int MusterFalse2[5]={1,2,1,2,1};
    int MusterMeasure[10];
    /* 
     * 
     *      |-|             dist_2
     *      |---|  |-|      dist_1
     *      ----------      dist_grund
     *--------------------- dist_band
     */
    
    
    int offset;         //Offset, um Maschinenvariationen zu beachten
    
    int dist_band;      //Mittlere Distanz zum Fließband
    int dist_grund;     //Mittlere Distanz zur Grundplatte
    int dist_1;         //MD zum 1. Baustein
    int dist_2;         //MD zun 2. Baustein
    
    int s;              //Rauschen / Messungenauigkeit
    
    
public:
    
    // Konstruktor & Destruktor
    HeightSensor(){
    }
    ~HeightSensor(){
    }
    
    // Methoden
    virtual void evalCycle();
    virtual bool result();


};
#endif	/* HEIGHTSENSOR_H */
