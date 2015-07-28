//
//  B3_MSTPNetwork.cpp
//  IO_Export
//
//  Created by Benjamin Bernays on 6/16/15.
//
//

#include "B3_MSTPNetwork.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
B3_MSTPNetwork::B3_MSTPNetwork(){
    
};
int B3_MSTPNetwork::getNextOpenSlot(){
    for(int i = 0;i<60;i++){
        if(!occupiedSlots[i]){
            return i;
        }
    }
    return 0;
}
void B3_MSTPNetwork::writeSelf(){
    std::cout <<"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
    std::cout <<"<ObjectSet ExportMode=\"Standard\" Version=\"1.6.1.5000\" Note=\"TypesFirst\">\n";
    std::cout <<"<MetaInformation>\n";
    std::cout <<"<ExportMode Value=\"Standard\" />\n";
    std::cout <<"<RuntimeVersion Value=\"1.6.1.5000\" />\n";
    std::cout <<"<SourceVersion Value=\"1.6.1.5000\" />\n";
    std::cout <<"<ServerFullPath Value=\"/QCC\" />\n";
    std::cout <<"</MetaInformation>\n";
    std::cout <<"<ExportedObjects>\n";
    for(int i = 0;i<60;i++){
        if(occupiedSlots[i]){
            slot[i]->writeSelf();
        }
    }
    std::cout <<"</ExportedObjects>\n";
    std::cout <<"</ObjectSet>\n";
    
}
void B3_MSTPNetwork::addController(B3_Controller* newModule, int newSlot){
    slot[newSlot] = newModule;
    if(!occupiedSlots[newSlot]){
        occupiedSlots[newSlot] = true;
    }
};
/*void setModuleType(char* newType, int slotNum){
 type
 };*/
B3_Controller* B3_MSTPNetwork::getController(int newSlot){
    if(occupiedSlots[newSlot]){
        return slot[newSlot];
    }
    else{
        return NULL;
    }
};