#define BTN D4

ResultData* resultsHistory[10];
int cntToHistoryResults = 0;

int lastBTNval;
unsigned long lastTimePress;
unsigned long releaseTime;
void BTN_setup(){
    pinMode(BTN, INPUT_PULLUP);
    lastBTNval = digitalRead(BTN);
    lastTimePress = millis();
    }
void BTN_loop(){
    int correntBTNval = digitalRead(BTN);
    if((correntBTNval == LOW )&& (lastBTNval == HIGH) && (millis() - lastTimePress  > 50)){
        lastTimePress = millis();
    }else if((correntBTNval == HIGH )&& (lastBTNval == LOW) && (millis() - lastTimePress > 5)){
        releaseTime = millis();
        Serial.print("press time => ");
        Serial.println(releaseTime-lastTimePress);
        Check_Time(releaseTime - lastTimePress); 
        lastTimePress = releaseTime;
    }
    lastBTNval = correntBTNval;
}


bool Compare_Data(unsigned long time,unsigned long bestResult){
    return (time < bestResult) ? true : false;
}
void Add_To_Press_Results(unsigned long time,bool newRecord){
    delete resultsHistory[(cntToHistoryResults) % 10]; 
    resultsHistory[(cntToHistoryResults) % 10] = new ResultData(cntToHistoryResults, time, newRecord);
    cntToHistoryResults++;
}
