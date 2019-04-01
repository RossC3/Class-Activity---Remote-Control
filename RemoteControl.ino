const int button = 2;
const int LED = 12;
int m = 500;
volatile int state = 0;

char code[] = "11011100010001";
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
  attachInterrupt(0, remote_ISR,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(state == 1){
    RC5_Button();
  }
}


void remote_ISR(){
  state = digitalRead(button);
  delay(500);
}

void RC5_Button(){
  for(int i = 0; i <=13; i++){
    if(code[i] == '1'){
      digitalWrite(LED,LOW);
      delay(.889*m);
      digitalWrite(LED,HIGH);
      delay(.889*m);
    }else{
      digitalWrite(LED,HIGH);
      delay(.889*m);
      digitalWrite(LED,LOW);
      delay(.889*m);
    }
  }
  state = 0;
  delay(500);
}

