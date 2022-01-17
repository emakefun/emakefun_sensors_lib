#define myEncoder_A 3
#define myEncoder_B 5
#define myEncoder_D 6

volatile int myEncoder_lastEncoded = 0;
volatile long myEncoder_encoderValue = 0;
long myEncoder_lastencoderValue = 0;
int myEncoder_lastMSB = 0;
int myEncoder_lastLSB = 0;

long myEncoder_readEncoderValue(void) {
  return myEncoder_encoderValue / 4;
}

boolean myEncoder_isButtonPushDown(void) {
  if (!digitalRead(myEncoder_D)) {
    delay(5);
    if (!digitalRead(myEncoder_D))
      return true;
    }
  return false;
}

void updateEncoder_myEncoder() {
  int MSB = digitalRead(myEncoder_A);
  int LSB = digitalRead(myEncoder_B);
  int encoded = (MSB << 1) | LSB;
  int sum  = (myEncoder_lastEncoded << 2) | encoded;
  if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) myEncoder_encoderValue ++;
  if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) myEncoder_encoderValue --;
  myEncoder_lastEncoded = encoded;
}

void setup(){
  pinMode(myEncoder_A, INPUT);
  pinMode(myEncoder_B, INPUT);
  pinMode(myEncoder_D, INPUT);
  digitalWrite(myEncoder_A, HIGH);
  digitalWrite(myEncoder_B, HIGH);
  Serial.begin(9600);
  attachInterrupt(0, updateEncoder_myEncoder, CHANGE);
  attachInterrupt(1, updateEncoder_myEncoder, CHANGE);

}

void loop(){
  if (myEncoder_isButtonPushDown()) {
    Serial.println("Encoder Button is Enter");
  }
  Serial.println(myEncoder_readEncoderValue());
  delay(100);
}