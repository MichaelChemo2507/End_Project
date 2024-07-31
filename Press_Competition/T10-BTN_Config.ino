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
    if((correntBTNval == LOW && lastBTNval == HIGH) && lastTimePress > 50){
        lastTimePress = millis();
        lastBTNval = correntBTNval;
        Serial.println("press");
    }else if(correntBTNval == HIGH && lastBTNval == LOW){
        lastBTNval = correntBTNval;
        releseTime = millis();
        Serial.println("relese");
    }
}