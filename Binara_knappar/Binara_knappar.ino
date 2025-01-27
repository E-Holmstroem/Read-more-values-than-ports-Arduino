int Inputport[] = {8,9,10};
int TotPins = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0;i < TotPins;i++){
    pinMode(Inputport[i], INPUT);
  }
  
}


void loop() {
  // put your main code here, to run repeatedly:
  String nums = "";
  for (int i = 0;i < TotPins; i++){
    nums += digitalRead(Inputport[i]);  
  }

  int btnVal = 0;
  for (int i = 0;i < TotPins; i++){
    btnVal += digitalRead(Inputport[i])*(1 << i);

  } 

  

  Serial.println(nums + " | " + btnVal);

}
