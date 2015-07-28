//
//  IO_Folder.h
//  IO_Export
//
//  Created by Benjamin Bernays on 6/14/15.
//
//

#ifndef __IO_Export__IO_Folder__
#define __IO_Export__IO_Folder__

#include <stdio.h>
#include "IO_Module.h"

class IO_Folder{
public:
    IO_Folder();
    void addModule(IO_Module*, int);
    IO_Module* getModule(int);
    void setModuleType(char*, int);
    void writeSelf();
protected:
    char* Name;
    char* type;
    IO_Module* slot[60] = {NULL};
    bool occupiedSlots[60] = {false};
};

#endif /* defined(__IO_Export__IO_Folder__) */
