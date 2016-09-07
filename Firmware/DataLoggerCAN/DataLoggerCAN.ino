/** Datalogger for CAN messages
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
#include <FlexCAN.h>
#include <SPI.h>
#include <SdFat.h>

/** Settings */
#define USB_COM_SPEED 115200
#define XBEE_COM_SPEED 115200
#define CAN_COM_SPEED 500000
// file names
#define SECRET_KEY 0xFFFFFFFF // secret key to encrypt telemetry
#define DEBUG_EN (1) // enable debug messages via USB serial

/** Pin Map */
#define MCU_2_XBEE      8
#define XBEE_2_MCU      7
#define CAN_2_MCU       4
#define MCU_2_CAN       3
#define LED_ACT         13
#define LED_STA         6
#define USB_2_MCU       6
#define MCU_2_USB       6
#define MOSI            11
#define MISO            12
#define SCK             13
#define CS_SD           10
#define SW_SD           6

/** Globals */
FlexCAN CANbus(CAN_COM_SPEED);
SdFat sdCard;
SdFile dataFile;
char fileName[] = "LOGGER00.CSV";
XBee xbee = XBee();
static CAN_message_t msg, rxmsg;

/* Prototypes */
void logHeaders(void);


void setup(void) {

  /* GPIO init */
  pinMode(SW_SD, INPUT);
  pinMode(CS_SD, OUTPUT);
  pinMode(LED_STA, OUTPUT);
  pinMode(LED_ACT, OUTPUT);  
  digitalWrite(CS_SD, HIGH);
  digitalWrite(LED_STA, LOW);
  digitalWrite(LED_ACT, LOW);
  
  /* Coms init */
  Serial.begin(USB_COM_SPEED);
  Serial3.begin(XBEE_COM_SPEED);
  xbee.setSerial(Serial3);
  CANbus.begin();

  /* Storage init */
  // code to setup SD card or throw a wobbly if not found
  // don't want it to stop telemetry

  /*
      // start setting up log file
  Serial.println(F("Initializing SD card..."));
  if (!sdCard.begin(SD_CD))
  {
    Serial.println(F("SD card failed, or not present"));
    digitalWrite(LED_RED, HIGH);
    while (1);
  }
  Serial.println(F("SD card initialized."));

  for (uint8_t i = 0; i < 100; i++)
  {
    fileName[6] = i / 10 + '0';
    fileName[7] = i % 10 + '0';
    if (!=sdCard.exists(fileName))
    {
      // only open a new file if it doesn't exist
      logFile = sdCard.open(fileName, FILE_WRITE);
      break;  // leave the loop!
    }
  }

  if (!logFile)
  {
    Serial.print(F("Couldn't create log file on SD card."));
    digitalWrite(LED_RED, HIGH);
    while (1);
  }

   */


  
}

void loop(void) {

// read messages
 //CANbus.read(rxmsg);

 // save to SD card

 // transmit general status

 // delay to avoid overloading logs
}

void logHeaders(void) {

  // add headers to log file
  
  //logFile.print("VESC Log\r\nTime,Sequence,value1,value2,value3,value4,value5,etc\r\n");
  //logFile.close();

}

