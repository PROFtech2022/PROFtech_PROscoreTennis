#include "Keymapping.h"
bool buttonPressed = false;

void KeyFunctions() {
  if (status_PB[PB_HomeScore] && !buttonPressed) {
    if (status_PB[PB_Shift]) {
      HomeScore--;
    } else {
      HomeScore++;
      if (HomeScore == 5) {
        HomeSet++;
      }
    }
  }

  if (status_PB[PB_GuestScore] && !buttonPressed) {
    if (shift_Pressed()) {
      GuestScore--;
    } else {
      GuestScore++;
      if (GuestScore == 5) {
        GuestSet++;
      }
    }
  }

  if (status_PB[PB_HomeSet] && !buttonPressed) {
    if (shift_Pressed()) {
      HomeSet--;
    } else {
      HomeSet++;
    }
  }

  if (status_PB[PB_GuestSet] && !buttonPressed) {
    if (shift_Pressed()) {
      GuestSet--;
    } else {
      GuestSet++;
    }
  }

  if (status_PB[PB_GameTimeSTARTSTOP] && !buttonPressed) {
    GT_started = !GT_started;
  }

  if (status_PB[PB_NowServing] && !buttonPressed) {
    if (shift_Pressed()) {
      NowServing = 0;
    } else {
      if (NowServing == 0) {
        NowServing = 1;
      } else if (NowServing == 1) {
        NowServing = 2;
      } else if (NowServing == 2) {
        NowServing = 1;
      } else {
        NowServing = 0;
      }
    }
  }

  if (PB_NoPress()) {
    buttonPressed = false;
  } else {
    buttonPressed = true;
  }

  delay(1);
}

bool shift_Pressed() {
  return status_PB[PB_Shift];
}