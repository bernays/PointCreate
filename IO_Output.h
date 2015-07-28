//
//  IO_Object_Output.h
//  IO_Export
//
//  Created by Benjamin Bernays on 5/22/15.
//
//

#ifndef __IO_Export__IO_Object_Output__
#define __IO_Export__IO_Object_Output__

#include <stdio.h>
#include "IO_Object.h"
#include "IO_Input.h"
using namespace std;

class OutputVoltage: public IO_Object{
public:
    OutputVoltage();
    OutputVoltage(char*Name);
    OutputVoltage(char * nameIn, int channelIn);
    void setOffset(int Offset);
    void setElecBottomOfScale(int);
    void setElecTopOfScale(int);
    void setEngBottomOfScale(int);
    void setEngTopOfScale(int);
    void setLogArray(int);
    void setThreshold(int);
    void setValue(int);
    void setElecUnit(int);
    void setEngScaleUnit(int);
    void setRequestedValue(int);
    int getOffset();
    int getElecBottomOfScale();
    int getElecTopOfScale();
    int getEngBottomOfScale();
    int getEngTopOfScale();
    int getLogArray();
    int getThreshold();
    int getValue();
    int getRequestedValue();
    void writeSelf();
protected:
    int Offset;
    int OffsetUnit;
    int ElecBottomOfScale;
    int ElecTopOfScale;
    int ElecUnit;
    int EngBottomOfScale;
    int EngTopOfScale;
    int EngScaleUnit;
    int LogArray;
    int Threshold;
    int Value;
    int requestedValue;
};
class OutputDigital: public IO_Object{
public:
    OutputDigital();
    OutputDigital(char*Name);
    OutputDigital(char * nameIn, int channelIn);
    int getValue();
    void writeSelf();
protected:
    int Value;
    
};

#endif /* defined(__IO_Export__IO_Object_Output__) */
