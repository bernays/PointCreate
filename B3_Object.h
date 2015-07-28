//
//  B3_Object.h
//  IO_Export
//
//  Created by Benjamin Bernays on 6/17/15.
//
//

#ifndef __IO_Export__B3_Object__
#define __IO_Export__B3_Object__

#include <stdio.h>
class B3_Object{
protected:
    int channel;
    char* name;
    const char* Note;
public:
    B3_Object();
    B3_Object(char* nameIn);
    B3_Object(char* nameIn, int channelIn);
    int getChannel();

    virtual void writeSelf();
    void setChannel(int);
    void setNote(const char*);

};

#endif /* defined(__IO_Export__B3_Object__) */
