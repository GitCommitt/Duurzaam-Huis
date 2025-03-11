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

  String jsonOutput;
  serializeJson(doc, jsonOutput);
  
  Serial.println(jsonOutput);
}
// for easy JSON debugging
void SendJSONToSerial() {
  serializeJson(doc, Serial);
  Serial.println();
}
