//
//  main.cpp
//  IO_Export
//
//  Created by Benjamin Bernays on 5/29/15.
//
//
#include <fstream>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include "IO_Object.h"
#include "IO_Input.h"
#include "IO_Output.h"
#include "RowHolder.h"
#include "tinyxml.h"
#include "IO_Folder.h"
#include "IO_Module.h"
#include "B3_Input.h"
#include "B3_Object.h"
#include "B3_MSTPNetwork.h"
#include "B3_Controller.h"

#define LOGNAME_FORMAT_IO "%Y%m%d_%H%M%S_IO.xml"
#define LOGNAME_FORMAT_B3 "%Y%m%d_%H%M%S_B3.xml"
#define LOGNAME_SIZE 30

char* splitName(const char* name){
    char * pch1;
    char * my_str = strdup(name);
    pch1 = strtok (my_str,"-");
    while (pch1 != NULL)
    {
        if (strcmp(pch1, "UI16") == 0) {
            return (char*)"UI16";
        }
        else if (strcmp(pch1, "UI8AO4")== 0) {
            return (char*)"UI8AO4";
        }
        else if (strcmp(pch1, "AOV8")== 0) {
            return (char*)"AOV8";
        }
        else if (strcmp(pch1, "AO8H")== 0) {
            return (char*)"AO8";
        }
        else if (strcmp(pch1, "DOFA12")== 0) {
            return (char*)"DOFA12";
        }
        else if (strcmp(pch1, "DOFC8H")== 0) {
            return (char*)"DOFC8";
        }
        else if (strcmp(pch1, "DOFC8")== 0) {
            return (char*)"DOFC8";
        }
        else if (strcmp(pch1, "UI8DOFC4")== 0) {
            return (char*)"UI8DOFC4";
        }
        else if (strcmp(pch1, "b3920")== 0) {
            return (char*)"b3920";
        }
        else if (strcmp(pch1, "b3814")== 0) {
            return (char*)"b3814";
        }
        else if (strcmp(pch1, "b3867")== 0) {
            return (char*)"b3867";
        }
        else if (strcmp(pch1, "b3866")== 0) {
            return (char*)"b3866";
        }
        else if (strcmp(pch1, "b3800")== 0) {
            return (char*)"b3800";
        }
        pch1 = strtok (NULL, "-");
    }
    return NULL;
}
char* controllerType(char* name){
    if (strcmp(name, "UI16") == 0) {
        return (char*)"cIO";
    }
    else if (strcmp(name, "UI8AO4")== 0) {
        return (char*)"cIO";
    }
    else if (strcmp(name, "AOV8")== 0) {
        return (char*)"cIO";
    }
    else if (strcmp(name, "AO8")== 0) {
        return (char*)"cIO";
    }
    else if (strcmp(name, "DOFA12")== 0) {
        return (char*)"cIO";
    }
    else if (strcmp(name, "DOFC8H")== 0) {
        return (char*)"cIO";
    }
    else if (strcmp(name, "DOFC8")== 0) {
        return (char*)"cIO";
    }
    else if (strcmp(name, "UI8DOFC4")== 0) {
        return (char*)"cIO";
    }

    else if (strcmp(name, "b3920")== 0) {
        return (char*)"b3";
    }
    else if (strcmp(name, "b3814")== 0) {
        return (char*)"b3";
    }
    else if (strcmp(name, "b3867")== 0) {
        return (char*)"b3";
    }
    else if (strcmp(name, "b3866")== 0) {
        return (char*)"b3";
    }
    else if (strcmp(name, "b3800")== 0) {
        return (char*)"b3";
    }
    return NULL;
}
int splitSlot(const char* name){
    char * pch;
    char * my_str = strdup(name);
    pch = strtok (my_str,"-");
    while (pch != NULL)
    {
        return atoi(&pch[4]);
    }
    return  NULL;
}

char* getName(char* name){
//void getName(const char* name){
    char* returnName;
    char * my_str = strdup(name);

    char* pch = strtok (my_str,"-");
    returnName = pch;
    pch = strtok (NULL, "-");
    
    int count = 0;
    while(my_str[count]) count++;
    char * my_str2 = strdup("_");

    returnName[count] = my_str2[0];
    returnName[count+1] = pch[0];
    
    //cout<<returnName<<"\n";
    return returnName;
}


int main( int argc, char **argv ){
    
    B3_MSTPNetwork b3_mstpnetwork;
    IO_Folder io_Folder;
    char *  filename =argv[1];
    RowHolder row;
    TiXmlDocument doc(filename);
    if(doc.LoadFile())
    {
        TiXmlHandle hDoc(&doc);
        TiXmlElement* pElem, *pTable,*pCell, *pData;
        int i,j,k =0;
        bool input = false;
        pElem = hDoc.FirstChild("Workbook").Child("Worksheet", 0).ToElement();
        for( pElem; pElem; pElem=pElem->NextSiblingElement() )
        {
            //cout<<(pElem->Attribute("ss:Name"))<<"\n";
            i=0; // keeps track of the row
            char * type = splitName(pElem->Attribute("ss:Name"));
            //splits name to find IO module type io16, ao8...
            //if the type is a valid IO module type then the parsing continues
            //otherwise the entire worksheet is considered irrelevant
            
            if(type && ( (strcmp(controllerType(type), "cIO")== 0)||(strcmp(controllerType(type), "b3")== 0))){
                int slot = splitSlot(pElem->Attribute("ss:Name")); //split name to retrieve slot number
                char * charStarName = strdup(pElem->Attribute("ss:Name"));
                IO_Module *module = new IO_Module(getName(charStarName)); //create new module with correct name
                B3_Controller *b3_controller = new B3_Controller(strtok (charStarName,"-"));
                if((strcmp(controllerType(type), "b3")== 0)){
                    k++;
                }
                else{
                    //getName(pElem->Attribute("ss:Name"));
                    
                }
                pTable =pElem->FirstChildElement("Table")->FirstChildElement("Row")->ToElement(); // get first row
                for( (pTable); pTable; pTable=pTable->NextSiblingElement() ){
                    //iterate through all rows
                    pCell=pTable->FirstChildElement("Cell")->ToElement();
                    i++;
                    j = 0;
                    
                    if(i>10)
                        input = false; // all points start after line 10 so infgormation prior to line 11 is ignored
                    for( pCell; pCell; pCell=pCell->NextSiblingElement() ){
                        j++; //keeps track of columns
                        pData =pCell->FirstChildElement("Data"); //text is stored in data element. not cell elements have data child
                        if(pData){
                            if(pData->ToElement()->GetText()) //get data text
                                //iterate through all other cells in that row and extract the information
                                if(i >=11 && j == 1 && strcmp (pCell->Attribute("ss:Index"),"2") == 0){
                                    row.update(strdup(pData->ToElement()->GetText()), j); // store the information in row object
                                }
                                else {
                                    if(i>=11 &&row.getPoint()){
                                        row.update(strdup(pData->ToElement()->GetText()), j);
                                    }
                                    else{
                                        
                                    }
                                }
                        }
                    }
                    
                    if(row.getColumns()>1 && (strcmp(controllerType(type), "cIO") == 0)){
                        int channelTempcIO =atoi(&row.getPoint()[2]);
                        module->addPoint(row.createPoint(), channelTempcIO); //save the data from the row in the IO module object as a point
                        //cout<<type<<"\n";
                        module->setType(type);
                        io_Folder.addModule(module, slot); //add the module to the IO Folder object

                    }
                    else if ((row.getColumns()>1 && (strcmp(controllerType(type), "b3") == 0))){
                        int channelTempcb3 =atoi(&row.getPoint()[2]);
                        char* pointype = row.getPoint();
                        pointype[2] = '\0';
                        if((strcmp(pointype, "IN") == 0)){
                            b3_controller->addInput(row.b3createPoint(channelTempcb3), channelTempcb3);}
                        else{
                            b3_controller-> addOutput(row.b3createPoint(channelTempcb3), channelTempcb3);
                        }
                        b3_controller->setType(type);
                        b3_mstpnetwork.addController(b3_controller,k); //add the module to the IO Folder object

                    }
                    row.clear(); // clear the row object completely so it can be reused for the next row of data
                    
                    
                    
                }
            }
        }
    }
    
    int PrintB3 = 0;
    int PrintIO = 0;
    for(int i;i<argc;i++){
        if (argv[i]) {
            if(strcmp(argv[i], "IO") == 0) PrintIO = 1;
        }
        if (argv[i]) {
            if(strcmp(argv[i], "B3") == 0) PrintB3 = 1;
        }
    }
    static char B3[LOGNAME_SIZE];
    static char IO[LOGNAME_SIZE];
    time_t now = time(0);
    strftime(B3, sizeof(B3), LOGNAME_FORMAT_B3, localtime(&now));
    strftime(IO, sizeof(IO), LOGNAME_FORMAT_IO, localtime(&now));

    //cout<<IO<<"\n";

    if (PrintIO) {
        FILE* file;
        file = freopen(IO,"w",stdout);
        io_Folder.writeSelf(); // write complete xml of all points stored in all IO_Modules
        fclose(file);

    }
    if (PrintB3) {
        FILE* file;
        file = freopen(B3,"w",stdout);
        b3_mstpnetwork.writeSelf();
        //fclose(stdout);
        fclose(file);
    }

        //freopen("outputb3.xml","w",stdout);
    //b3_mstpnetwork.writeSelf();
    return 0;
};