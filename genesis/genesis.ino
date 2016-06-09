#include "UnoJoy.h"

// NOTE: Pins 0, 1 and 13 are used by UnoJoy for Serial Comm. // 

int GEN_PIN_1 = 11;
int GEN_PIN_2 = 2;
int GEN_PIN_3 = 3;
int GEN_PIN_4 = 4;

int GEN_PIN_6 = 6;
int GEN_PIN_7 = 7;
int GEN_PIN_9 = 9;

int buttons[8];

void setup(){
  setupPins();
  setupUnoJoy();
}


void loop(){
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
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

dataForController_t getControllerData(void){
    
    pollController();

    dataForController_t controllerData = getBlankDataForController();

    if(buttons[0] == 0){
       controllerData.dpadUpOn = 1;
    }
    
    if(buttons[1] == 0){
      controllerData.dpadDownOn = 1;
    }
    
    if(buttons[2] == 0){
        controllerData.dpadLeftOn = 1;
    }
    
    if(buttons[3] == 0){
      controllerData.dpadRightOn = 1;
    }
    
    if(buttons[4] == 0){
      controllerData.squareOn = 1;
    }
    
    if(buttons[5] == 0){
      controllerData.startOn = 1;
    }
    
    if(buttons[6] == 0){
      controllerData.crossOn = 1;
    }
    
    if(buttons[7] == 0){
      controllerData.circleOn = 1;
    }
   
  return controllerData;
}
