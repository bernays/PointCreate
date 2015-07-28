//
//  IO_Folder.cpp
//  IO_Export
//
//  Created by Benjamin Bernays on 6/14/15.
//
//

#include "IO_Folder.h"
IO_Folder::IO_Folder(){
    
};
void IO_Folder::writeSelf(){

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
void IO_Folder::addModule(IO_Module* newModule, int newSlot){
    slot[newSlot] = newModule;
    if(!occupiedSlots[newSlot]){
        occupiedSlots[newSlot] = true;
    }
};
/*void setModuleType(char* newType, int slotNum){
    type
};*/
IO_Module* IO_Folder::getModule(int newSlot){
    if(occupiedSlots[newSlot]){
        return slot[newSlot];
    }
    else{
        return NULL;
    }
};
