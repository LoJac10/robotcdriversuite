#pragma config(Sensor, S1,     MSSMUX,         sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: mindsensors-sensormux-test2.c 133 2013-03-10 15:15:38Z xander $
 */

/**
 * mindsensors-sensormux.h provides an API for the Mindsensors SensorMUX Sensor.
 * This program demonstrates how to create a small disco party in your LEGO room
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to Mindsensors for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.59 AND HIGHER. 

 * Xander Soldaat (xander_at_botbench.com)
 * 30 March 2010
 * version 0.1
 */

// Copy these to your brick
#define MONNKEY01 "monkey01.ric"
#define MONNKEY02 "monkey02.ric"
#define MONNKEY03 "monkey03.ric"
#define MONNKEY04 "monkey04.ric"
#define MONNKEY05 "monkey05.ric"
#define MONNKEY06 "monkey06.ric"
#define MONNKEY07 "monkey07.ric"

#include "mindsensors-sensormux.h"

tSensors disco[] = {sensorCOLORGREEN, sensorCOLORBLUE, sensorCOLORRED};

task danceMOnkeyDance()
{
  const int X_COORD = 30;
  const int Y_COORD = 0;
  const int WAITTIME = 100;

  while (true) {
    nxtDisplayRICFile(X_COORD,Y_COORD, MONNKEY01);
    wait1Msec(WAITTIME);
    nxtDisplayRICFile(X_COORD,Y_COORD, MONNKEY02);
    wait1Msec(WAITTIME);
    nxtDisplayRICFile(X_COORD,Y_COORD, MONNKEY03);
    wait1Msec(WAITTIME);
    nxtDisplayRICFile(X_COORD,Y_COORD, MONNKEY04);
    wait1Msec(WAITTIME);
    nxtDisplayRICFile(X_COORD,Y_COORD, MONNKEY05);
    wait1Msec(WAITTIME);
    nxtDisplayRICFile(X_COORD,Y_COORD, MONNKEY06);
    wait1Msec(WAITTIME);
    nxtDisplayRICFile(X_COORD,Y_COORD, MONNKEY07);
    wait1Msec(WAITTIME);
  }
}

task main()
{
  long counter = 0;
  nxtDisplayCenteredTextLine(0, "Mindsensors");
  nxtDisplayCenteredBigTextLine(1, "SnsrMUX");
  nxtDisplayCenteredTextLine(3, "Test 2");
  nxtDisplayCenteredTextLine(5, "Connect LEGO");
  nxtDisplayCenteredTextLine(6, "Color Sensors");
  nxtDisplayCenteredTextLine(7, "to ports 1-4");

  wait1Msec(2000);
  eraseDisplay();
  StartTask(danceMOnkeyDance);

  // Let's get the party started!
  while(true)
  {
    // Set the channel to a random one
    MSSMUXsetChan(MSSMUX, (counter++%4) + 1);
    // Set the sensor to a random colour, R, G or B
    SetSensorType(MSSMUX, disco[abs(rand() % 3)]);
    // Wait a random time before switching
    wait1Msec(abs(rand() % 100) + 100);
    // Do a little dance!
  }
}