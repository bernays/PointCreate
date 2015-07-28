//
//  B3_Input.h
//  IO_Export
//
//  Created by Benjamin Bernays on 6/17/15.
//
//

#ifndef __IO_Export__B3_Input__
#define __IO_Export__B3_Input__

#include <stdio.h>
#include "B3_Object.h"
class B3_input_Analog: public B3_Object{
public:
    B3_input_Analog();
    B3_input_Analog(char*Name);
    B3_input_Analog(char * nameIn, int channelIn);
    void setElectricType(int);
    void setCOVIncrement(int);
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
    int getElectricType();
    int getCOVIncrement();
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
    int ElectricType;
    int COVIncrement;
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
class B3_input_Digital: public B3_Object{
public:
    B3_input_Digital();
    B3_input_Digital(char*Name);
    B3_input_Digital(char * nameIn, int channelIn);
    int getValue();
    void writeSelf();
    void setActiveText(char*);
    void setInactiveText(char*);
    char* ActiveText;
    char* InactiveText;
protected:
    int Value;
    
};

#endif /* defined(__IO_Export__B3_Input__) */
