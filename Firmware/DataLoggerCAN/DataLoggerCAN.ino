/** Datalogger for VESC CAN messages
   @detail Logs CAN messages from a network of connected VESC speed controllers. These messages will be saved locally to SD card (with timestamps) as well as transmitted via XBee to a remote terminal
   
   Requires:
     SD Card
     XBee RF TRX
     Teensy 3.2
   
   Can't seem to find any concrete information on VESC CANBUS messages. I'm assuming each VESC (once programmed with a unique ID) will transmit status messages including:
     battery voltage, current, board temperature, motor temperature, motor RPMs, throttle
   The plan will be to log this to the SD card with timestamps (Teensy 3.2 includes a real time clock)
   In addition certain information (undecided as to which) will be forwarded via XBee for real time feedback

   @status just place holder code for now.

   @author @pinski1_
   @date 06/09/2016

*/
#include <XBee.h>
#include <SPI.h>
#include <SdFat.h>

/** Settings */
#define USB_COM_SPEED 115200
#define XBEE_COM_SPEED 115200
// file names
#define SECRET_KEY 0xFFFFFFFF // secret key to encrypt telemetry
#define DEBUG_EN (1) // enable debug messages via USB serial

/** Pin Map */
#define MCU_2_XBEE      D8
#define XBEE_2_MCU      D7
#define CAN_2_MCU       D4
#define MCU_2_CAN       D3
#define LED_ACT         D13
#define LED_STA         
#define USB_2_MCU       
#define MCU_2_USB       
#define MOSI            D11
#define MISO            D12
#define SCK             D13
#define CS_SD           D10
#define SW_SD           0

/** Globals */
// CAN init
SdFat sd;
SdFile dataFile;
XBee xbee = XBee();





void setup(void) {

  Serial.begin(USB_COM_SPEED);
  Serial3.begin(XBEE_COM_SPEED);
  
  xbee.setSerial(Serial3);
  
  pinMode(SW_SD, INPUT);
  pinMode(LED_STA, OUTPUT);
  pinMode(LED_ACT, OUTPUT);
  
  digitalWrite(LED_STA, LOW);
  digitalWrite(LED_ACT, LOW);
}

void loop(void) {



}
