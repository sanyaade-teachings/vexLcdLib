#pragma config(UART_Usage, UART1, User_Control)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                        Copyright (c) James Pearman                          */
/*                                   2013                                      */
/*                            All Rights Reserved                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*    Module:     serialLcdDemo.c                                              */
/*    Author:     James Pearman                                                */
/*    Created:    17 October 2013                                              */
/*                                                                             */
/*    Revisions:                                                               */
/*                V1.00  17 Oct 2013 - Initial release                         */
/*-----------------------------------------------------------------------------*/
/*   Test the lcdLib library                                                   */
/*-----------------------------------------------------------------------------*/

#include "lcdLib.c"

// Task to display the button data from the second LCD
task buttonDisplayer()
{
    while(1)
        {
        wait1Msec(200);
        writeDebugStreamLine("Button is %02X", nLCDButtons2 );
        }
}

task main()
{
    string  str;
    int     i;

    // start the button displayer task
    StartTask(buttonDisplayer);
    // LCD on uart1 with custom serial driver
    wait1Msec(100);

    // Init the second LCD on uart 1
    vexLcdInit(UART1);
    // backlight on
    vexLcdBacklight(1);

    // check set function
    vexLcdSet( 0, "vexLcdSet" );
    vexLcdSet( 1, "Test" );
    wait1Msec(1000);
    // check clearline function
    vexLcdClearLine(0);
    vexLcdClearLine(1);
    wait1Msec(1000);
    // check LCD at function
    vexLcdSetAt( 0, 5, "vexLcdSet" );
    vexLcdSetAt( 1, 5, "Test" );
    wait1Msec(1000);

    // flash backlight
    for(i=0;i<10;i++)
        {
        vexLcdBacklight(0);
        wait1Msec(100);
        vexLcdBacklight(1);
        wait1Msec(100);
        }

    // do forever
    while( true )
      {
      // program time into string
      sprintf( str, "%.3f", nPgmTime/1000.0);

      // send string to LCD top line
      vexLcdSet( 0, "Program time" );
      // send string to LCD lower line
      vexLcdSet( 1, str );

      wait1Msec(50);
      }
}
