//Variables used in this system are written here

//Scores
uint8_t HomeScore = 30;
uint8_t GuestScore = 50;

//Set Score
uint8_t HomeSet = 0;
uint8_t GuestSet = 0;

//Game Time
uint8_t GameTime_Minute = 0;
uint8_t GameTime_Second = 0;
uint8_t GameTime_Millis = 0;

uint8_t NowServing = 0;

//msc
bool SetupMode = false;
uint8_t DataToSet = 0;

//interrupts
uint16_t isr_tmr_GTcounter = 0;
bool GT_started = false;

//Push Buttons
uint8_t PB_ScanCount = 0;
bool status_PB[18];  //16+2 just to be sure