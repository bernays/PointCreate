//
//  IO_Digital.h
//  IO_Export
//
//  Created by Benjamin Bernays on 5/22/15.
//
//

#ifndef __IO_Export__IO_Digital__
#define __IO_Export__IO_Digital__

#include <stdio.h>
#include "IO_Object.h"
#include "IO_Input.h"
#include "IO_Output.h"
#include "B3_Object.h"

class RowHolder{
public:
    RowHolder();
    RowHolder(char*Name);
    void writeSelf();
    void update(char*name, int column);
    int getColumns();
    void clear();
    void setPoint(char*Name);
    char* getPoint();
    void setConnectionType(char*Name);
    void setDeviceBomTag(char*Name);
    void setSoftwareTag(char*Name);
    void setPointType(char*Name);
    void setDevicePartNum(char*Name);
    void setDeviceMfg(char*Name);
    void setSoftwareInformation(char*Name);
    void setSigRangeLow(char*Name);
    void setSigRangeHi(char*Name);
    void setEngRangeLow(char*Name);
    void setEngRangeHi(char*Name);
    void setOffValue(char*Name);
    void setOnValue(char*Name);
    IO_Object* createPoint();
    B3_Object* b3createPoint(int);

protected:
    char* Point;
    char* ConnectionType;
    char*DeviceBomTag;
    char*SoftwareTag;
    char*PointType;
    char*DevicePartNum;
    char*DeviceMfg;
    char*SoftwareInformation;
    char*SigRangeLow;
    char*SigRangeHi;
    char*EngRangeLow;
    char*EngRangeHi;
    char*offValue;
    char*onValue;
    
};


#endif /* defined(__IO_Export__IO_Digital__) */
