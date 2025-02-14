void setup() {
  // put your setup code here, to run once:
  pinMode(D6, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D3, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D6, HIGH);

 delay (500);

  digitalWrite(D6, LOW);

 delay (500);

   digitalWrite(D5, HIGH);

 delay (500);

  digitalWrite(D5, LOW);

  delay (500);

   digitalWrite(D3, HIGH);

 delay (500);

  digitalWrite(D3, LOW);

 delay (500);
}
