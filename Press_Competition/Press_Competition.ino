#define DISPLAY_MODE D2
bool dispalyMode;
void setup(){
    pinMode(DISPLAY_MODE, INPUT_PULLUP);
    dispalyMode = (digitalRead(DISPLAY_MODE)) ? true : false;
    if(dispalyMode)
        BTN_setup();
}
void loop(){
    if(dispalyMode)
        BTN_loop();
}