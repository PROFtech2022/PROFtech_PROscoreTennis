void verifyVariable() {

  if (HomeScore >= 5 && HomeScore != 255) {
    HomeScore = 0;
  } else if (HomeScore == 255) {
    HomeScore = 4;
  }



  if (GuestScore >= 5 && GuestScore != 255) {
    GuestScore = 0;
  } else if (GuestScore == 255) {
    GuestScore = 0;
  }



  if (HomeSet >= 10 && HomeSet < 255) {
    HomeSet = 9;
  } else if (HomeSet == 255) {
    HomeSet = 0;
  }

  if (GuestSet >= 10 && GuestSet < 255) {
    GuestSet = 9;
  } else if (GuestSet == 255) {
    GuestSet = 0;
  }

  if (GameTime_Millis >= 10) {
    GameTime_Millis = 0;
    GameTime_Second++;
  }

  if (GameTime_Second >= 60) {
    GameTime_Second = 0;
    GameTime_Minute++;
  }
}
