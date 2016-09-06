

/** Datalogger for CAN messages
   @detail Logs CAN messages from a network of connected VESC speed controllers. These messages will be saved locally to SD card (with timestamps) as well as transmitted via XBee to a remote terminal

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
// file formats
// secret key

/** Pin Map */
#define MCU_2_XBEE D8
#define XBEE_2_MCU D7
#define XBEE_RESET D9
#define CAN_2_MCU D4
#define MCU_2_CAN D3
#define LED_ACT D13
#define LED_STA 0
#define USB_2_MCU
#define MCU_2_USB
#define MOSI D11
#define MISO  D12
#define SCK D13
#define CS_SD     D10


/** Globals */
// CAN init
SdFat sd;
SdFile dataFile;
XBee xbee = XBee();





void setup(void) {

  Serial.begin(USB_COM_SPEED);
  Serial3.begin(XBEE_COM_SPEED);

  xbee.setSerial(Serial3);

  pinMode(XBEE_RESET, OUTPUT);
  pinMode(LED_STA, OUTPUT);
  pinMode(LED_ACT, OUTPUT);

  digitalWrite(XBEE_RESET, HIGH);
  digitalWrite(LED_STA, LOW);
  digitalWrite(LED_ACT, LOW);
}

void loop(void) {



}

