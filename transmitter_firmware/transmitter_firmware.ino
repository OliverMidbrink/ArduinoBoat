
int joyPinX = A0;
int joyPinY = A1;
int potPin = A3;

float joyX = 0;
float joyY = 0;

float pot = 0;

long timeLog = 0;


void setup() {
 Serial.begin(115200);
 Serial1.begin(9600);
 
}

void loop() {
  joyX = map(analogRead(joyPinX),0,1023,1000,2000);
  joyY = map(analogRead(joyPinY),0,1023,1000,2000);
  //Serial.println((String(joyX)+"\t"+String(joyY)+"\t"+String(pot)));
  
  pot = map(analogRead(potPin),0,800,-1000,1000);

  int outputLeft = int(round(constrain(joyY+pot, 1000, 2000)));
  int outputRight = int(round(constrain(joyY-pot, 1000, 2000)));

  Serial1.print('l');
  Serial1.print(outputLeft);
  Serial1.print(' ');

  Serial1.print('r');
  Serial1.print(outputRight);
  Serial1.print(' ');

  Serial.print(outputLeft + "\t\t" + outputRight);

  if(millis()-timeLog > 200){
    timeLog = millis();
    Serial1.print('o');
  }
  
}
