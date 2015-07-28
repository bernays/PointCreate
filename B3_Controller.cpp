//
//  B3_Controller.cpp
//  IO_Export
//
//  Created by Benjamin Bernays on 6/16/15.
//
//
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "B3_Controller.h"

B3_Controller::B3_Controller(){
    
};
B3_Controller::B3_Controller(char*newName){
    Name = newName;
};
void B3_Controller::setType(char* newType){
    ModelName = newType;
};
void B3_Controller::addInput(B3_Object* newPoint, int channel){
    if(newPoint){
        Input_holder[channel] = newPoint;
        if(!occupiedInputs[channel]){
            occupiedInputs[channel] = true;
        }
    }
};
void B3_Controller::addOutput(B3_Object* newPoint, int channel){
    if(newPoint){
        Output_holder[channel] = newPoint;
        if(!occupiedOutputs[channel]){
            occupiedOutputs[channel] = true;
        }
    }
};



B3_Object* B3_Controller::getInput(int channel){
    if(occupiedInputs[channel]){
        return Input_holder[channel];
    }
    else{
        return NULL;
    }
};

B3_Object* B3_Controller::getOutput(int channel){
    if(occupiedOutputs[channel]){
        return Output_holder[channel];
    }
    else{
        return NULL;
    }
};
void B3_Controller::writeSelf(){
    
    std::cout <<"<OI DESCR=\""<< Name<<"\""<<" NAME=\""<<Name<< "\" TYPE=\"bacnet.b3.Device\">\n";
    
    std::cout <<"<PI Name=\"APDUSegmentTimeout\" Value=\"2000\" />\n";
    std::cout <<"<PI Name=\"BackupFailureTimeout\" Value=\"0\" />\n";
    std::cout <<"<PI Name=\"DaylightSavingsStatus\" Value=\"0\" />\n";
    std::cout <<"<PI Name=\"MaxInfoFrames\" Value=\"2\" />\n";
    std::cout <<"<PI Name=\"MaxMaster\" Value=\"127\" />\n";
    std::cout <<"<PI Name=\"MaxSegmentsAccepted\" Value=\"0\" />\n";
    std::cout <<"<PI Name=\"ModelName\" Value=\""<<ModelName<<"\" />\n";
    std::cout <<"<PI Name=\"ProfileName\" Value=\"\" />\n";
    std::cout <<"<PI Name=\"UTCOffset\" Value=\"0\" />\n";
    std::cout <<"<OI NAME=\"Application\" TYPE=\"bacnet.b3.B3ApplicationProxy\" declared=\"1\">\n";
    for(int i = 0;i<60;i++){
        if(occupiedInputs[i]){
            Input_holder[i]->writeSelf();
        }
    }
    for(int i = 0;i<60;i++){
        if(occupiedOutputs[i]){
            Output_holder[i]->writeSelf();
        }
    }
    std::cout <<"</OI>\n";

    std::cout <<"</OI>\n";
    
};