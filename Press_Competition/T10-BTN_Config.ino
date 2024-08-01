#define BTN D4

int lastBTNval;
unsigned long lastTimePress;
unsigned long releseTime;
void BTN_setup(){
    pinMode(BTN, INPUT_PULLUP);
    lastBTNval = digitalRead(BTN);
    lastTimePress = millis();
    releseTime = millis();
}
void BTN_loop(){
    int correntBTNval = digitalRead(BTN);
    if((correntBTNval == LOW )&& (lastBTNval == HIGH) && (millis() - lastTimePress  > 50)){
        lastTimePress = millis();
    }else if((correntBTNval == HIGH )&& (lastBTNval == LOW) && (millis() - lastTimePress > 5)){
        Serial.print("press time => ");
        Serial.println(millis()-lastTimePress);
        lastTimePress = millis();
    }
    lastBTNval = correntBTNval;
}