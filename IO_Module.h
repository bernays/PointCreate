//
//  IO_Module.h
//  IO_Export
//
//  Created by Benjamin Bernays on 6/14/15.
//
//

#ifndef __IO_Export__IO_Module__
#define __IO_Export__IO_Module__

#include <stdio.h>
#include "IO_Object.h"

class IO_Module{
public:
    IO_Module();
    IO_Module(char*Name);
    void setType(char*);
    void addPoint(IO_Object*, int);
    IO_Object* getPoint(int);
    void writeSelf();
protected:
    char* Name;
    char* type;
    IO_Object* holder[17] = {NULL}; // all IO modules have fewer than 16 ports (0 is not used).
    bool occupiedchannels[17] = {false}; // all channels are instantiated to be empty and as points are assied
};

#endif /* defined(__IO_Export__IO_Module__) */
