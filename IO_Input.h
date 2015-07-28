//
//  IO_Object_Input.h
//  IO_Export
//
//  Created by Benjamin Bernays on 5/22/15.
//
//

#ifndef __IO_Export__IO_Object_Input__
#define __IO_Export__IO_Object_Input__

#include <stdio.h>
#include "IO_Object.h"
#include "IO_Output.h"

class InputVoltage: public IO_Object{
public:
    InputVoltage();
    InputVoltage(char*Name);
    InputVoltage(char * nameIn, int channelIn);
    void setOffset(int Offset);
    void setElecBottomOfScale(int);
    void setElecTopOfScale(int);
    void setEngBottomOfScale(int);
    void setEngTopOfScale(int);
    void setValue(int);
    void setElecUnit(int);
    void setEngScaleUnit(int);
    int getValue();
    void writeSelf();
protected:
    int ElecBottomOfScale;
    int ElecTopOfScale;
    int ElecUnit;
    int EngBottomOfScale;
    int EngTopOfScale;
    int EngScaleUnit;
    int LogArray;
    int Value;
    
};
class InputCurrent: public IO_Object{
    
public:
    InputCurrent();
    InputCurrent(char*Name);
    InputCurrent(char * nameIn, int channelIn);
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
    int getOffset();
    int getElecBottomOfScale();
    int getElecTopOfScale();
    int getEngBottomOfScale();
    int getEngTopOfScale();
    int getLogArray();
    int getThreshold();
    int getValue();
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
    
};
class InputDigital: public IO_Object{
public:
    InputDigital();
    InputDigital(char*Name);
    InputDigital(char * nameIn, int channelIn);
    int getValue();
    void writeSelf();
protected:
    int Value;
    
};
class InputTemperature: public IO_Object{
public:
    InputTemperature();
    InputTemperature(char*Name);
    InputTemperature(char * nameIn, int channelIn);
    int getValue();
    int getThermistor();
    void setThermistor(int);
    void writeSelf();
protected:
    int Thermistor;
    int Value;
    
};

#endif /* defined(__IO_Export__IO_Object_Input__) */
