//
//  B3_MSTPNetwork.h
//  IO_Export
//
//  Created by Benjamin Bernays on 6/16/15.
//
//

#ifndef __IO_Export__B3_MSTPNetwork__
#define __IO_Export__B3_MSTPNetwork__

#include <stdio.h>
#include "B3_Controller.h"
class B3_MSTPNetwork{
public:
    B3_MSTPNetwork();
    void addController(B3_Controller*, int);
    B3_Controller* getController(int);
    void setControllerType(char*, int);
    int getNextOpenSlot();
    void writeSelf();
protected:
    char* Name;
    char* type;
    B3_Controller* slot[60] = {NULL};
    bool occupiedSlots[60] = {false};
};
#endif /* defined(__IO_Export__B3_MSTPNetwork__) */
