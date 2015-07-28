//
//  B3_Controller.h
//  IO_Export
//
//  Created by Benjamin Bernays on 6/16/15.
//
//

#ifndef __IO_Export__B3_Controller__
#define __IO_Export__B3_Controller__

#include <stdio.h>
#include "B3_Object.h"
class B3_Controller{
public:
    B3_Controller();
    B3_Controller(char*Name);
    void setType(char*);
    void addInput(B3_Object*, int);
    void addOutput(B3_Object*, int);
    B3_Object* getInput(int);
    B3_Object* getOutput(int);
    void writeSelf();
protected:
    char* Name;
    char* ModelName;
    B3_Object* Input_holder[60] = {NULL}; // all IO modules have fewer than 16 ports (0 is not used).
    B3_Object* Output_holder[60] = {NULL}; // all IO modules have fewer than 16 ports (0 is not used).
    bool occupiedOutputs[60] = {false};
    bool occupiedInputs[60] = {false}; // all channels are instantiated to be empty and as points are assigned
};
#endif /* defined(__IO_Export__B3_Controller__) */


