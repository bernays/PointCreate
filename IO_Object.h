//
//  IO_Object.h
//  IO_Export
//
//  Created by Benjamin Bernays on 5/22/15.
//
//

#ifndef __IO_Export__IO_Object__
#define __IO_Export__IO_Object__
#include <iostream>
#include <stdio.h>
class IO_Object{
protected:
    int channel;
    char* name;
    const char* Note;
public:
    IO_Object(); 
    IO_Object(char* nameIn);
    IO_Object(char* nameIn, int channelIn);
    int getChannel();
    virtual void writeSelf();
    void setChannel(int);
    void setNote(const char*);

};

#endif /* defined(__IO_Export__IO_Object__) */
