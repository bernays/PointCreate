//
//  IO_Object.cpp
//  IO_Export
//
//  Created by Benjamin Bernays on 5/22/15.
//
//

#include "IO_Object.h"
using namespace std;

IO_Object::IO_Object(){
    channel = NULL;
    name = NULL;
}

IO_Object:: IO_Object(char * nameIn){
    channel = NULL;
    name = nameIn;
    cout<< "    IO_Object " <<nameIn << "default constructed." << endl;

}
IO_Object:: IO_Object(char * nameIn, int channelIn){
    channel = channelIn;
    name = nameIn;
}

int IO_Object::getChannel(){
    return channel;
}
void IO_Object::setChannel(int inChannel){
    channel = inChannel;
}
void IO_Object::writeSelf(){
    //blank because the base class IO object is not meant to be used
}
void IO_Object:: setNote(const char* note){
    Note = note;
}