//Communication Data Structure
// Max size of this struct is 32 bytes - NRF24L01 buffer limit
struct Payload_Data {
  uint8_t HomeScore = 0;
  uint8_t GuestScore = 0;

  uint8_t HomeSet=0;
  uint8_t GuestSet=0;

  uint8_t GameTime_Minute = 0;
  uint8_t GameTime_Second = 0;
  uint8_t GameTime_Millis = 0;

  uint8_t NowServing = 0;
};

Payload_Data payload;  // Create a variable with the above structure