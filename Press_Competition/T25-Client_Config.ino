  #include <ESP8266WiFi.h>
  #include <WiFiClient.h>
  #include <WiFiUdp.h>
  #include <ESP8266HTTPClient.h>

const char* ssid = "Michael_wifi";
const char* pswd = "87654321";


  WiFiClient client;
  int server_port = 80;//http
  unsigned long restartRecord = 5000;

void wifiClient_Setup() {
  Serial.println("wifiSetup");
  WiFi.begin(ssid,pswd);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.println("trying ...");
        delay(100);
    }
  Update_Data(restartRecord);
    Serial.println("Connected to network");
}

unsigned long Get_Data() {
    unsigned long ret = -1;
    HTTPClient http;
    String dataURL = "http://api.kits4.me/GEN/api.php?";
    dataURL += "ACT=GET&DEV=1121&CH=1";
    http.begin(client, dataURL);
    int httpCode = http.GET();
    Serial.println(httpCode);
    if (httpCode == HTTP_CODE_OK) {
        Serial.print("HTTP response code ");
        Serial.println(httpCode);
        String Res = http.getString();
        Serial.println(Res);
        ret = Res.toInt();
    }
    http.end();
    return ret;
}
void Update_Data(unsigned long data) {
    HTTPClient http;
    String dataURL = "http://api.kits4.me/GEN/api.php?";
    dataURL += "ACT=SET&DEV=1121&CH=1&VAL=";
    dataURL += String(data);
    http.begin(client, dataURL);
    int httpCode = http.GET();
    Serial.println(httpCode);
    if (httpCode == HTTP_CODE_OK) {
        Serial.print("HTTP response code ");
        Serial.println(httpCode);
    }
    http.end();
}

  
