const int pin13 =  13;      //pin for 1 On
const int pin12 =  12;      //pin for 2 On
const int pin11 =  11;      //pin for 2 Off
const int pin10 =  10;      //pin for 1 Off

int input = 0;        //the input recieved (which plug and to turn off or on)
int state = 0;        //input recieved, run once
void setup() {
    pinMode(pin13, OUTPUT); 
    pinMode(pin12, OUTPUT);
    pinMode(pin11, OUTPUT);
    pinMode(pin10, OUTPUT);
    digitalWrite(pin13, LOW);
    digitalWrite(pin12, LOW);
    digitalWrite(pin11, LOW);
    digitalWrite(pin10, LOW);
    Serial.begin(9600); // Default connection rate for my BT module
}
void loop() {
    if(Serial.available() > 0){
      input = Serial.read();
      state=0;
    }
    //Plug 1 Off
    if (input == '0') {
        if(state == 0){
          digitalWrite(pin10, HIGH);
          delay(1000);
          digitalWrite(pin10, LOW);
          Serial.println("Plug 1 off");
          state = 1;
        }
    }
    //Plug 1 On
    else if (input == '1') {
        if(state == 0){
          digitalWrite(pin13, HIGH);
          delay(1000);
          digitalWrite(pin13, LOW);
          Serial.println("Plug 1 on");
          state = 1;
        }
    }
    
    //Plug 2 Off
    if (input == '3') {
        if(state == 0){
          digitalWrite(pin11, HIGH);
          delay(1000);
          digitalWrite(pin11, LOW);
          Serial.println("Plug 2 off");
          state = 1;
        }
    }
    //Plug 2 On
    else if (input == '4') {
        if(state == 0){
          digitalWrite(pin12, HIGH);
          delay(1000);
          digitalWrite(pin12, LOW);
          Serial.println("Plug 2 on");
          state = 1;
        }
    }
}
