#include "Arduino.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <EEPROM.h>
#include "variables.h"
#include "PTWDTSB_DataStructure.h"
#include "Keymapping.h"

RF24 NRF(A0, A1);  // CE, CSN
const byte address[6] = "PT001";

#define LED_RED 10
#define batteryPin A2

#define PB_test false  //for testing push button assignment

void setup() {
  Serial.begin(9600);
  Serial.println("PROscore for TENNIS Transmitter\nSYSTEM START...");

  pinMode(LED_RED, OUTPUT);


  for (int x = 0; x < 10; x++) {
    digitalWrite(LED_RED, LOW);
    delay(100);
    digitalWrite(LED_RED, HIGH);
    delay(100);
  }

  if (!NRF.begin()) {
    while (1) {
      digitalWrite(LED_RED, HIGH);
      delay(50);
      digitalWrite(LED_RED, LOW);
      delay(50);
      digitalWrite(LED_RED, HIGH);
      delay(50);
      digitalWrite(LED_RED, LOW);
      delay(50);
      digitalWrite(LED_RED, HIGH);
      delay(50);
      digitalWrite(LED_RED, LOW);
      delay(1000);
    }
  }

  NRF.setPALevel(RF24_PA_MAX);
  NRF.setDataRate(RF24_250KBPS);
  NRF.openWritingPipe(address);

  PushButton_Setup();

  PSABTinterrupt_setup();
}

void loop() {
  KeyFunctions();
  
  verifyVariable();
  
  NRF_SendData();
}

void NRF_SendData() {
  switch (HomeScore) {
    case 0:
      payload.HomeScore = 0;
      break;
    case 1:
      payload.HomeScore = 15;
      break;
    case 2:
      payload.HomeScore = 30;
      break;
    case 3:
      payload.HomeScore = 40;
      break;
    case 4:
      payload.HomeScore = 50;
      break;
  }

  switch (GuestScore) {
    case 0:
      payload.GuestScore = 0;
      break;
    case 1:
      payload.GuestScore = 15;
      break;
    case 2:
      payload.GuestScore = 30;
      break;
    case 3:
      payload.GuestScore = 40;
      break;
    case 4:
      payload.GuestScore = 50;
      break;
  }

  payload.HomeSet = HomeSet;
  payload.GuestSet = GuestSet;

  payload.GameTime_Minute = GameTime_Minute;
  payload.GameTime_Second = GameTime_Second;
  payload.GameTime_Millis = GameTime_Millis;

  NRF.write(&payload, sizeof(Payload_Data));
  //Serial.println("NRFsent");
}
