#pragma config(Sensor, S1,     HTIRR,               sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
 * HTIRL-driver.h provides an API for the HiTechnic IR Receiver Sensor.  This program
 * demonstrates how to use the IR Receiver API to display the currently transmitted
 * motor powers.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: More comments
 *
 * Credits:
 * - Big thanks to HiTechnic for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.10 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 25 November 2009
 * version 0.2
 */

#include "hitechnic-irrecv.h"

/*
  =============================================================================
  main task with some testing code

 */
task main {
  displayCenteredTextLine(0, "HiTechnic");
  displayCenteredBigTextLine(1, "IR Recv");
  displayCenteredTextLine(3, "Test 1");
  displayCenteredTextLine(5, "Connect sensor");
  displayCenteredTextLine(6, "to S1");
  sleep(2000);
  eraseDisplay();

  // Create struct to hold sensor data
  tHTIRR irReceiver;

  // Initialise and configure struct and port
  initSensor(&irReceiver, S1);

  while (true) {
    // Read the data from the sensor
    if (!readSensor(&irReceiver)) {
      displayTextLine(4, "ERROR!!");
      sleep(2000);
      stopAllTasks();
    }

    for (short i = 0; i < 4; i++) {
      // Read the motor powers sent by the remote on the specified channel
      // and display them.
      displayTextLine(i, "%4d, %4d", irReceiver.motA[i], irReceiver.motB[i]);
      sleep(10);
    }
  }
}
