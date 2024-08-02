#define PIN_LED_R D1
#define PIN_LED_G D2
#define PIN_LED_B D3

void LED_setup(){
    pinMode(PIN_LED_R, OUTPUT);
    pinMode(PIN_LED_G, OUTPUT);
    pinMode(PIN_LED_B, OUTPUT);
}
void LED_loop(){
    
}
void LED_On(int Red, int Green, int Blue) {
  analogWrite(PIN_LED_R, Red);
  analogWrite(PIN_LED_G, Green);
  analogWrite(PIN_LED_B, Blue);
}
void LED_Off() {
  analogWrite(PIN_LED_R, 0);
  analogWrite(PIN_LED_G, 0);
  analogWrite(PIN_LED_B, 0);
}