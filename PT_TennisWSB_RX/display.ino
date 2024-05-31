void display_PROscoreTennis() {
  display_HomeScore(HomeScore);
  display_HomeSet(HomeSet);
  display_GameTime(GameTime_Minute, GameTime_Second, GameTime_Millis, false);
  display_GuestSet(GuestSet);
  display_GuestScore(GuestScore);
}


void display_HomeScore(uint8_t score) {
  if (score >= 50) {
    SevenSeg.printOneDigit('A');
    SevenSeg.printOneDigit('D');
  } else {
    SevenSeg.printByte(score, false);
  }
}

void display_GuestScore(uint8_t score) {
  if (score >= 50) {
    SevenSeg.printOneDigit('A');
    SevenSeg.printOneDigit('D');
  } else {
    SevenSeg.printByte(score, false);
  }
}

void display_HomeSet(uint8_t set) {
  if (NowServing == 1) {
    SevenSeg.printOneDigit(set + 100);
  } else {
    SevenSeg.printOneDigit(set);
  }
}

void display_GuestSet(uint8_t set) {
  if (NowServing == 2) {
    SevenSeg.printOneDigit(set + 100);
  } else {
    SevenSeg.printOneDigit(set);
  }
}


void display_GameTime(uint8_t Minute, uint8_t Second, uint8_t Millis, bool Display_Millis) {
  SevenSeg.printOneDigit(Minute / 10 );
  SevenSeg.printOneDigit(Minute % 10);
  SevenSeg.printOneDigit((Second / 10) + 100);
  SevenSeg.printOneDigit((Second % 10) + 100);
}
