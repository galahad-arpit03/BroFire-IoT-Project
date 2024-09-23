#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""
void setup() {
  // put your setup code here, to run once:
pinMode(D0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D0,HIGH);
  delay(500);
  digitalWrite(D0,LOW);
  delay(500);


}
