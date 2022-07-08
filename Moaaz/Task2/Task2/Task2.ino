int btnPin[] = { 0,7,6,5,4,3,2 };
int ledPin[] = { 0,13,12,11,10,9,8 };
int buttonState[] = { 0,0,0,0,0,0,0 };
int lastButtonState[] = { 0,0,0,0,0,0,0 };
int led = 0;
int btn = 0;
int i = 0;
int ctrl = 0;
int lastBtn = 0;
int out = 0 ;
void setup() {
  Serial.begin(9600);
  Serial.println("Starting");
  pinMode(led, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(led, OUTPUT);
  for (led = 8; led <= 13; led++) { pinMode(led, OUTPUT); }
  for (btn = 2; btn <= 7;  btn++) { pinMode(btn, INPUT);  }

  
}

void loop() {
  for (i = 1; i <= 6; i++) {
    if (wasBtnPushed(i) > 0) {
      if (wasBtnPushed(i) != lastBtn) {
        Serial.print("last_btn_");Serial.print(lastBtn);
        Serial.print("   curr_btn_"); Serial.print(i); 
        Serial.print("   initial_ctrl_"); Serial.print(ctrl); 
        if (ctrl == 0 && wasBtnPushed(i) == 1) { ctrl = 1; digitalWrite(ledPin[i], HIGH); }
        if (ctrl == 1 && wasBtnPushed(i) == 2) { ctrl = 2; digitalWrite(ledPin[i], HIGH);}
        if (ctrl == 2 && wasBtnPushed(i) == 3) { ctrl = 3; digitalWrite(ledPin[i], HIGH);}
        if (ctrl == 3 && wasBtnPushed(i) == 4) { ctrl = 4; digitalWrite(ledPin[i], HIGH);}
        if (ctrl == 4 && wasBtnPushed(i) == 5) { ctrl = 5; digitalWrite(ledPin[i], HIGH);}
        if (ctrl == 5 && wasBtnPushed(i) == 6) { ctrl = 6; digitalWrite(ledPin[i], HIGH);}
       
        if (ctrl == 0 && wasBtnPushed(i) == 2) { reset(); }
        if (ctrl == 0 && wasBtnPushed(i) == 3) { reset(); }
        if (ctrl == 0 && wasBtnPushed(i) == 4) { reset(); }
        if (ctrl == 0 && wasBtnPushed(i) == 5) { reset(); }
        if (ctrl == 0 && wasBtnPushed(i) == 6) { reset(); }
  
        if (ctrl == 1 && wasBtnPushed(i) == 3) { reset(); }
        if (ctrl == 1 && wasBtnPushed(i) == 4) { reset(); }
        if (ctrl == 1 && wasBtnPushed(i) == 5) { reset(); }
        if (ctrl == 1 && wasBtnPushed(i) == 6) { reset(); }
  
        if (ctrl == 2 && wasBtnPushed(i) == 1) { reset(); }
        if (ctrl == 2 && wasBtnPushed(i) == 4) { reset(); }
        if (ctrl == 2 && wasBtnPushed(i) == 5) { reset(); }
        if (ctrl == 2 && wasBtnPushed(i) == 6) { reset(); }
  
        if (ctrl == 3 && wasBtnPushed(i) == 1) { reset(); }
        if (ctrl == 3 && wasBtnPushed(i) == 2) { reset(); }
        if (ctrl == 3 && wasBtnPushed(i) == 5) { reset(); }
        if (ctrl == 3 && wasBtnPushed(i) == 6) { reset(); }
  
        if (ctrl == 4 && wasBtnPushed(i) == 1) { reset(); }
        if (ctrl == 4 && wasBtnPushed(i) == 2) { reset(); }
        if (ctrl == 4 && wasBtnPushed(i) == 3) { reset(); }
        if (ctrl == 4 && wasBtnPushed(i) == 6) { reset(); }
  
        if (ctrl == 5 && wasBtnPushed(i) == 1) { reset(); }
        if (ctrl == 5 && wasBtnPushed(i) == 2) { reset(); }
        if (ctrl == 5 && wasBtnPushed(i) == 3) { reset(); }
        if (ctrl == 5 && wasBtnPushed(i) == 4) { reset(); }
        
        Serial.print("   ctrl_"); Serial.println(ctrl);
        lastBtn = wasBtnPushed(i);
        delay(100);
      }
    if (ctrl == 6) { 
      digitalWrite(out,HIGH);
      Serial.print("Correct!");
      delay(2000); 
      reset(); 
    
    
    }
    }
  }
}

void reset() {
  for(led = 1; led <= 6; led++) {
    digitalWrite(ledPin[led], LOW);
  }
  Serial.print("has reset all");
  ctrl = 0;
  lastBtn = 0;
}

int wasBtnPushed(int x) {
  buttonState[x] = digitalRead(btnPin[x]);
    if (buttonState[x] != lastButtonState[x]) {
      if (buttonState[x] == HIGH) { return x; }
    }
  lastButtonState[x] = buttonState[x];
}
