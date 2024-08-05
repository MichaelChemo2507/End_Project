
#define DISPLAY_MODE D2
bool isDispalyMode;
void setup(){
    Serial.begin(9600);
    pinMode(DISPLAY_MODE, INPUT_PULLUP);
    isDispalyMode = (digitalRead(DISPLAY_MODE) == LOW) ? true : false;
    if(isDispalyMode){
        wifi_Setup();
    }else{
        wifiClient_Setup();
        BTN_setup();
        LED_setup();
    }
}
void loop(){
    if(isDispalyMode){
        wifi_loop();
    }
    else{
        BTN_loop();
        LED_loop();
    }
}