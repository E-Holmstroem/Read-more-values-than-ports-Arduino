int Inputport[] = {9,10,11};
int Outputport[] = {2,3,4,5,6,7,8};
int TotInPins = 3;
int TotOutPins = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int i = 0;i < TotInPins;i++){
    pinMode(Inputport[i], INPUT_PULLUP);
  }
  for (int i = 0;i < TotOutPins;i++){
    pinMode(Outputport[i], OUTPUT);
  } 
}

void loop() {
  int btnVal = 0;
  for (int i = 0;i < TotInPins; i++){
    btnVal += digitalRead(Inputport[i])*(1 << i);

  } 

  Serial.println(btnVal);

  //Gauss elimination of 5 inputs options when wanting 7 segment display gives

  int x = digitalRead(11);
  int y = digitalRead(10);
  int z = digitalRead(9);

  int segA = y || (!x && !y && !z) || (x && !y && z);
  int segB = !x || (!z && x && !y) || (x && y && z);
  int segC = x || z || (!x && !y);
  int segD = (!x && !z) || (x && y && z) || (!x && y && z) || (x && !y && z);
  int segE = (!x && !z) || (x && y && !z);
  int segF = (x && !y) || (x && !z) || (!x && !y && !z);
  int segG = (!x && y) || (x && !y) || (x && !z);

  digitalWrite(2, segA);
  digitalWrite(3, segB);
  digitalWrite(4, segC);
  digitalWrite(5, segD);
  digitalWrite(6, segE);
  digitalWrite(7, segF);
  digitalWrite(8, segG);


}
