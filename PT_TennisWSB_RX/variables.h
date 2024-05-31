//Variables used in this system are written here

#define BuzzerPin 2

//Scores
uint8_t HomeScore = 0;
uint8_t GuestScore = 0;

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

uint32_t blinker_millis = 0;
bool blink = false;
