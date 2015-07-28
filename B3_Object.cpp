//
//  B3_Object.cpp
//  IO_Export
//
//  Created by Benjamin Bernays on 6/17/15.
//
//

#include "B3_Object.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

B3_Object::B3_Object(){
    channel = NULL;
    name = NULL;
}

B3_Object:: B3_Object(char * nameIn){
    channel = NULL;
    name = nameIn;
    std::cout<< "    B3_Object " <<nameIn << "default constructed." << endl;
    
}
B3_Object:: B3_Object(char * nameIn, int channelIn){
    channel = channelIn;
    name = nameIn;
}

int B3_Object::getChannel(){
    return channel;
}
void B3_Object::setChannel(int inChannel){
    channel = inChannel;
}
void B3_Object::writeSelf(){
    //blank because the base class IO object is not meant to be used
}
void B3_Object:: setNote(const char* note){
    Note = note;
}