/*
    PROscore Tennis Edition ---> Receiver Code
    Version 2024.1.0.1

    by: KennyNeutron

    Date Started: 05-31-2024
    Date Finished: N/A
*/
#include "Arduino.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "PTWDTSB_DataStructure.h"
#include "SN74HC595.h"
#include "variables.h"

RF24 NRF(A0, A1);  // CE, CSN
const byte address[6] = "PT001";

SN74HC595 SevenSeg;
void setup() {
  Serial.begin(9600);
  Serial.println("PROscore for TENNIS Receiver\nSYSTEM START...");
  SevenSeg.begin(8, 9, 10, 3);

  pinMode(BuzzerPin, OUTPUT);
  digitalWrite(BuzzerPin, 0);

  if (!NRF.begin()) {
    while (1) {
      SevenSeg.printOneDigit('E');
      SevenSeg.printOneDigit('R');
      SevenSeg.latchData();
    }
  }
  NRF.setPALevel(RF24_PA_MAX);
  NRF.setDataRate(RF24_250KBPS);

  NRF.openReadingPipe(0, address);
  NRF.startListening();

  display_PROscoreTennis();
  SevenSeg.latchData();
}

void loop() {
  if (NRF.available()) {
    NRF.read(&payload, sizeof(Payload_Data));  // Read the whole data and store it into the 'data' structure

    HomeScore = payload.HomeScore;
    GuestScore = payload.GuestScore;

    HomeSet = payload.HomeSet;
    GuestSet = payload.GuestSet;

    GameTime_Minute = payload.GameTime_Minute;
    GameTime_Second = payload.GameTime_Second;
    GameTime_Millis = payload.GameTime_Millis;

    NowServing = payload.NowServing;

    delay(1);
    display_PROscoreTennis();
    SevenSeg.latchData();
  }
}
