
int GEN_PIN_1 = 11;
int GEN_PIN_2 = 2;
int GEN_PIN_3 = 3;
int GEN_PIN_4 = 4;

int GEN_PIN_6 = 6;
int GEN_PIN_7 = 7;
int GEN_PIN_9 = 9;

int buttons[8];

void setup(){
  Serial.begin(9600);
  setupPins();
  Serial.print("Aye aye, good to go captain!");
}


void loop(){
  printButtons();
}

void setupPins(void){
  pinMode(GEN_PIN_1, INPUT);
  pinMode(GEN_PIN_2, INPUT);
  pinMode(GEN_PIN_3, INPUT);
  pinMode(GEN_PIN_4, INPUT);
  pinMode(GEN_PIN_6, INPUT);
  pinMode(GEN_PIN_9, INPUT);

  pinMode(GEN_PIN_7, OUTPUT); //This is the select pin
  digitalWrite(GEN_PIN_7, LOW);
}

void pollController(void){
    // First poll.
    buttons[0] = digitalRead(GEN_PIN_1);
    buttons[1] = digitalRead(GEN_PIN_2);
    buttons[2] = digitalRead(GEN_PIN_3);
    buttons[3] = digitalRead(GEN_PIN_4);
    buttons[4] = digitalRead(GEN_PIN_6);
    buttons[5] = digitalRead(GEN_PIN_9);

    // Select to high...
    digitalWrite(GEN_PIN_7, HIGH);

    // Second poll.
    buttons[0] = digitalRead(GEN_PIN_1);
    buttons[1] = digitalRead(GEN_PIN_2);
    buttons[2] = digitalRead(GEN_PIN_3);
    buttons[3] = digitalRead(GEN_PIN_4);
    buttons[6] = digitalRead(GEN_PIN_6);
    buttons[7] = digitalRead(GEN_PIN_9);

    // Select to low...
    digitalWrite(GEN_PIN_7, LOW);
}

void printButtons(void){
    
    pollController();

    if(buttons[0] == 0){
      Serial.println("UP");
    }
    
    if(buttons[1] == 0){
      Serial.println("DOWN");
    }
    
    if(buttons[2] == 0){
      Serial.println("LEFT");
    }
    
    if(buttons[3] == 0){
      Serial.println("RIGHT");
    }
    
    if(buttons[4] == 0){
      Serial.println("A");
    }
    
    if(buttons[5] == 0){
      Serial.println("START");
    }
    
    if(buttons[6] == 0){
      Serial.println("B");
    }
    
    if(buttons[7] == 0){
      Serial.println("C");
    }    
}

