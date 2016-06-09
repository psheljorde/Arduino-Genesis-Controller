#include "UnoJoy.h"

// Necesitamos 9 pins para este pedo
// Ponle nombres creativos.
// NOTE: Pins 0, 1 and 13 are used by UnoJoy for Serial Comm. // Este pinche vivo.

int buttons[8]; //do the que pedo

void setup(){
  setupPins();
  setupUnoJoy();
}


void loop(){
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
}

void setupPins(void){
//Aqui seteamos los pins de este pedo al modo correcto
//Todos son digitales y hay que setear selct a low (creo)

}

dataForController_t getControllerData(void){
    // Tengo que investigar como hacer el interrupt en select y mandar el pedo correcto.
    // Aqui va some sort of abstraction que polea con los controles que son malos,MANDA select, y polea con los controles que son peores.
    // Calcuvestigar el normal polling rate.
    // Hacer un arreglo de pins/botones, polear low, polear high, guardar el valor en un arreglo y luegoooo....
    
    
    dataForController_t controllerData = getBlankDataForController();
    if(buttons[0] == 0){
       controllerData.square = 1;
    }
    
    if(buttons[1] == 0){
      controllerData.cross = 1;
    }
    
    if(buttons[2] == 0){
        controllerData.circle = 1;
    }
    
    if(buttons[3] == 0){
      controllerData.startOn = 1;
    }
    
    if(buttons[4] == 0){
      controllerData.dpadUpOn = 1;
    }
    
    if(buttons[5] == 0){
      controllerData.dpadDownOn = 1;
    }
    
    if(buttons[6] == 0){
      controllerData.dpadLeftOn = 1;
    }
    
    if(buttons[7] == 0){
      controllerData.dpadRightOn = 1;
    }
   
  return controllerData;
    
}

