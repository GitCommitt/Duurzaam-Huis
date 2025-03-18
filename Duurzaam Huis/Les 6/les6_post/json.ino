// JSON API: https://arduinojson.org/v6/api/

// JSON libraries
#include <ArduinoJson.h>

// JSON document
JsonDocument doc;

void CreateJSON() {
  StaticJsonDocument<256> doc;
  static int attempt = 0;
  doc["attempt"] = ++attempt;
  doc["temperature"] = Temperature;
  doc["humidity"] = Humidity;
  doc["heat_index"] = HeatIndex;
  doc["ldr_value"] = analogRead(LDR_Pin);

  serializeJson(doc, jsonOut);
  
  Serial.println(jsonOut);
}
// for easy JSON debugging
void SendJSONToSerial() {
  serializeJson(doc, Serial);
  Serial.println();
}

void ReadJSON(String resJSON){

  resJSON.remove(0, 9);

  StaticJsonDocument<200> resDoc;
  deserializeJson(resDoc, resJSON);

Serial.println(String(bool(resDoc["lights"][0])));
  digitalWrite(D3, bool(resDoc["lights"][0]));
  digitalWrite(D5, bool(resDoc["lights"][1]));
  digitalWrite(D6, bool(resDoc["lights"][2]));
  }
