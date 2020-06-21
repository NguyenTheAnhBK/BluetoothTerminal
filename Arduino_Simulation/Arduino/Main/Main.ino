#include <ArduinoJson.h>

int ledPin = 5;
String controlSig = "";

void setup() {
  Serial.begin(9600); 
  Serial.println("Configuring, please wait...");

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}

void loop() {
  while(Serial.available()){
    char c = Serial.read();
    controlSig += c;
  }
  delay(10);
  if(controlSig.length() > 0){
    Serial.println(controlSig);
    DynamicJsonDocument doc(1024);
    deserializeJson(doc, controlSig);
    JsonObject data = doc.as<JsonObject>();
  
    digitalWrite(ledPin, (bool)data["l"]);
    controlSig = "";
  }
  delay(100);
}
