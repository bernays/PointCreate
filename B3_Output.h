//
//  B3_Output.h
//  IO_Export
//
//  Created by Benjamin Bernays on 6/17/15.
//
//

#ifndef __IO_Export__B3_Output__
#define __IO_Export__B3_Output__

#include <stdio.h>
#include "B3_Object.h"
class B3_OutputDigital: public B3_Object{
public:
    B3_OutputDigital();
    B3_OutputDigital(char*Name);
    B3_OutputDigital(char * nameIn, int channelIn);
    void setActiveText(char*);
    void setInactiveText(char*);
    char* getActiveText();
    char* getInactiveText();
    int getValue();
    char* ActiveText;
    char* InactiveText;
    void writeSelf();
protected:
    int Value;
    
};
class B3_output_Analog: public B3_Object{
public:
    B3_output_Analog();
    B3_output_Analog(char*Name);
    B3_output_Analog(char * nameIn, int channelIn);
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
    int ElectricType; //Will always be null unless  == 2
    int COVIncrement;
    int ElecBottomOfScale;
    int ElecTopOfScale;
    //int ElecUnit;
    int EngBottomOfScale;
    int EngTopOfScale;
    int EngScaleUnit;
    //int LogArray;
    //int Value;
    
};


#endif /* defined(__IO_Export__B3_Output__) */
