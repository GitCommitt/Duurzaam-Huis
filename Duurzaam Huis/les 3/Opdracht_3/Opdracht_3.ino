#include <ArduinoJson.h>

JsonDocument doc;
char jsonOut[128];

void setup() {
  pinMode(D6, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D3, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int delaytime = random (100, 500);
  int ldr_Value = analogRead(A0);
  delay (500);
Serial.println(ldr_Value);
Serial.println(delaytime);


CreateJSON( ldr_Value );

bool licht()
{
   return false;
}



  if(ldr_Value > 500){
    delay(delaytime);
    digitalWrite(D3, HIGH);
    delay(delaytime);
    digitalWrite(D3, LOW);
  }
}

void CreateJSON(  int value ) {
  doc["ldr"] = value;

  serializeJson(doc, jsonOut);

  serializeJson(doc, Serial);
}

CreateJSO(  ) {

}
