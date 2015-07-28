//
//  IO_Module.cpp
//  IO_Export
//
//  Created by Benjamin Bernays on 6/14/15.
//
//

#include "IO_Module.h"
#include "IO_Object.h"
IO_Module::IO_Module(){
    
};
IO_Module::IO_Module(char*newName){
    Name = newName;
};
void IO_Module::setType(char* newType){
    type = newType;
};
void IO_Module::addPoint(IO_Object* newPoint, int channel){
    holder[channel] = newPoint;
    if(!occupiedchannels[channel]){
        occupiedchannels[channel] = true;
    }
};
IO_Object* IO_Module::getPoint(int channel){
    if(occupiedchannels[channel]){
        return holder[channel];
    }
    else{
        return NULL;
    }
};
void IO_Module::writeSelf(){
    
    std::cout <<"<OI DESCR=\""<< Name<<"\""<<" NAME=\""<<Name<< "\" TYPE=\"io."<<type <<"\">\n";
    for(int i = 0;i<17;i++){
        if(occupiedchannels[i]){
            holder[i]->writeSelf();
        }
    }
    std::cout <<"</OI>\n";
    
};