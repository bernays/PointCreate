//
//  IO_Digital.cpp
//  IO_Export
//
//  Created by Benjamin Bernays on 5/22/15.
//
//
#include <sstream>
#include "RowHolder.h"
#include "B3_Input.h"
#include "B3_Output.h"
#include <stdio.h>
#include <string.h>
int getUnit(char* string){
    if(strcmp(string, "0") == 0) {
        
    }

    char pch2[40];
    char* pch = strtok (string," ");
    while (pch != NULL){
        for (int i = 0; pch[i] != '\0'; i++)
            pch[i] = (char)tolower(pch[i]);
        if((strcmp(pch, "V") == 0)) return 3276801;
        if((strcmp(pch, "ppm") == 0)) return 2097154;
        if((strcmp(pch, "degreeF") == 0)) return 2621443;
        if((strcmp(pch, "RH") == 0)) return 1507329;
        if((strcmp(pch, "%") == 0)) return 2097153;
        if((strcmp(pch, "cfm") == 0)) return 983044;
        if((strcmp(pch, "gpm") == 0)) return 983048;
        if((strcmp(pch, "psi") == 0)) return 2293763;
        if((strcmp(pch, "wc") == 0)) return 2293765;
        if((strcmp(pch, "fpm") == 0)) return 3211269;
        if((strcmp(pch, "%rh") == 0)) return 1507329;
        if((strcmp(pch, "psig") == 0)) return 2293763;
        if((strcmp(pch, "psid") == 0)) return 2293763;
        if((strcmp(pch, "feet") == 0)) return 1638403;
        if((strcmp(pch, "open") == 0)) return 2097153;
        if((strcmp(pch, "bypass") == 0)) return 2097153;

        //memcpy(pch2,pch,40);
        pch = strtok (NULL, " ");
    }
    
    //cout<<pch2<<"\n";
    return 0;
    
}
int getValue(char* string){
    char* pch = strtok (string," ");
    return atoi(pch);
}
RowHolder::RowHolder(){
    Point = NULL;
    ConnectionType = NULL;
    DeviceBomTag = NULL;
    SoftwareTag = NULL;
    SoftwareInformation = NULL;
    PointType = NULL;
    DevicePartNum = NULL;
    DeviceMfg = NULL;
    SigRangeLow = NULL;
    SigRangeHi = NULL;
    EngRangeLow = NULL;
    EngRangeHi = NULL;
    offValue = NULL;
    onValue = NULL;
};
void RowHolder::setPoint(char*Name){
    Point = Name;
}
char* RowHolder::getPoint(){
    return Point;
}
void RowHolder::setConnectionType(char*Name){
    ConnectionType = Name;
}
void RowHolder::setDeviceBomTag(char*Name){
    DeviceBomTag = Name;
}
void RowHolder::setSoftwareTag(char*Name){
    SoftwareTag = Name;
}
void RowHolder::setPointType(char*Name){
    PointType = Name;
}
void RowHolder::setDevicePartNum(char*Name){
    DevicePartNum = Name;
}
void RowHolder::setDeviceMfg(char*Name){
    DeviceMfg = Name;
}
void RowHolder::setSoftwareInformation(char*Name){
    SoftwareInformation = Name;
}
void RowHolder::setSigRangeLow(char*Name){
    SigRangeLow = Name;
}
void RowHolder::setSigRangeHi(char*Name){
    SigRangeHi = Name;
}
void RowHolder::setEngRangeLow(char*Name){
    EngRangeLow = Name;
}
void RowHolder::setEngRangeHi(char*Name){
    EngRangeHi = Name;
}
void RowHolder::setOnValue(char*Name){
    onValue = Name;
}
void RowHolder::setOffValue(char*Name){
    offValue = Name;
}

void RowHolder::clear(){
    Point = NULL;
    SoftwareInformation = NULL;
    ConnectionType = NULL;
    DeviceBomTag = NULL;
    SoftwareTag = NULL;
    PointType = NULL;
    DevicePartNum = NULL;
    DeviceMfg = NULL;
    SigRangeLow = NULL;
    SigRangeHi = NULL;
    EngRangeLow = NULL;
    EngRangeHi = NULL;
    offValue = NULL;
    onValue = NULL;
    
}
void RowHolder::writeSelf(){
    if(Point){
        cout <<Point<<"| "<<flush;}
    if(ConnectionType){
        cout <<ConnectionType<<"| "<<flush;}
    if(DeviceBomTag){
        cout <<DeviceBomTag<<"| "<<flush;}
    if(SoftwareTag){
        cout <<SoftwareTag<<"| "<<flush;}
    if(PointType){
        cout <<PointType<<"| "<<flush;}
    if(DevicePartNum){
        cout <<DevicePartNum<<"| "<<flush;}
    if(DeviceMfg){
        cout <<DeviceMfg<<"| "<<flush;}
    if(SoftwareInformation){
        cout <<SoftwareInformation<<"| "<<flush;}
    if(SigRangeLow){
        cout <<SigRangeLow<<"| "<<flush;}
    if(SigRangeHi){
        cout <<SigRangeHi<<"| "<<flush;}
    if(EngRangeLow){
        cout <<EngRangeLow<<"| "<<flush;}
    if(EngRangeHi){
        cout <<EngRangeHi<<"| "<<flush;}
    if(offValue){
        cout <<offValue<<"| "<<flush;}
    if(onValue){
        cout <<onValue <<"| "<<flush;}
    if(Point) cout<<"\n";
}
int RowHolder::getColumns(){
    int i = 0;
    if(Point){
        i++;}
    if(ConnectionType){
        i++;}
    if(DeviceBomTag){
        i++;}
    if(SoftwareTag){
        i++;}
    if(PointType){
        i++;}
    if(DevicePartNum){
        i++;}
    if(DeviceMfg){
        i++;}
    if(SoftwareInformation){
        i++;}
    if(SigRangeLow){
        i++;}
    if(SigRangeHi){
        i++;}
    if(EngRangeLow){
        i++;}
    if(EngRangeHi){
        i++;}
    if(offValue){
        i++;}
    if(onValue){
        i++;}
    return  i;
}
void RowHolder::update( char* CellContent, int column){
    switch (column) {
        case 1:
            Point = CellContent;
            break;
        case 2:
            ConnectionType = CellContent;
            break;
        case 3:
            DeviceBomTag = CellContent;
            break;
        case 4:
            SoftwareTag = CellContent;
            break;
        case 5:
            PointType = CellContent;
            break;
        case 6:
            DevicePartNum = CellContent;
            break;
        case 7:
            DeviceMfg = CellContent;
            break;
        case 8:
            SigRangeLow = CellContent;
            break;
        case 9:
            SigRangeHi = CellContent;
            break;
        case 10:
            EngRangeLow = CellContent;
            break;
        case 11:
            EngRangeHi = CellContent;
            break;
        case 12:
            offValue = CellContent;
            break;
        case 13:
            onValue = CellContent;
            break;
    }
}

IO_Object* RowHolder::createPoint(){
    char *type = Point;
    int channel;
    std::stringstream str;
    str << &(Point[2]);
    str >> channel;
    
    type[2] = '\0';
    IO_Object* blank = new IO_Object;
    char* temp{NULL};
    if(PointType) temp =strstr (PointType,"Thermistor");
    
    char* input = strstr (Point,"I");
    char* universalInput = NULL;
    char* digitalInput = NULL;
    char* digitalOutput = NULL;
    char* AnalogInput = NULL;
    char* AnalogOutput = NULL;
    if(ConnectionType) {
        universalInput =strstr (ConnectionType,"UI");
        digitalInput =strstr (ConnectionType,"DI");
        digitalOutput = strstr (ConnectionType,"DO");
        AnalogInput =strstr (ConnectionType,"AI");
        AnalogOutput = strstr (ConnectionType,"AO");
    }
    else{
        
    }
    if(digitalInput|| AnalogInput || universalInput){
        if(temp){
            InputTemperature* io_Temp = new InputTemperature(SoftwareTag);
            io_Temp->setChannel(channel);
            io_Temp->setThermistor(1); //hard coded thermistor Type1 (continuum)
            blank->~IO_Object();
            return io_Temp;}
        else if (digitalInput){
            InputDigital* io_Digital = new InputDigital(SoftwareTag);
            io_Digital->setChannel(channel);
            blank->~IO_Object();
            return io_Digital;}
        else if ((strcmp(PointType, "4-20 mA") == 0)){
            InputVoltage* io_Current = new InputVoltage(SoftwareTag);
            if(EngRangeHi){
                io_Current->setEngScaleUnit(getUnit(EngRangeHi));
                io_Current->setEngTopOfScale(getValue(EngRangeHi));}
            
            else{
                io_Current->setEngTopOfScale(100);
                io_Current->setEngScaleUnit(0);}
            if(EngRangeLow){
                io_Current->setEngBottomOfScale(getValue(EngRangeLow));}
            else{
                io_Current->setEngBottomOfScale(0);}
            
            if(SigRangeLow){
                io_Current->setElecBottomOfScale(2);}
            else{
                io_Current->setElecBottomOfScale(2);}
            
            if(SigRangeHi){
                io_Current->setElecTopOfScale(10);}
            else{
                io_Current->setElecTopOfScale(10);}
            
            if(!EngRangeHi || !EngRangeLow || !SigRangeLow || !SigRangeHi){
                io_Current->setNote("VALUE OF RANGE NOT KNOWN And Converted to Voltage input");
            }
            else{
                io_Current->setNote("Converted to Voltage input");
            }
            
            io_Current->setChannel(channel);
            blank->~IO_Object();
            return io_Current;
        }
        else if ((strcmp(PointType, "0-10 VDC") == 0) ||(strcmp(PointType, "2-10 VDC") == 0) ||getUnit(SigRangeHi) == 3276801){
            InputVoltage* io_Voltage = new InputVoltage(SoftwareTag);
            if(EngRangeHi){
                io_Voltage->setEngScaleUnit(getUnit(EngRangeHi));
                io_Voltage->setEngTopOfScale(getValue(EngRangeHi));}
            
            else{
                io_Voltage->setEngTopOfScale(100);
                io_Voltage->setEngScaleUnit(0);}
            if(EngRangeLow){
                io_Voltage->setEngBottomOfScale(getValue(EngRangeLow));}
            else{
                io_Voltage->setEngBottomOfScale(0);}
            
            if(SigRangeLow){
                io_Voltage->setElecBottomOfScale(getValue(SigRangeLow));}
            else{
                io_Voltage->setElecBottomOfScale(0);}
            
            if(SigRangeHi){
                io_Voltage->setElecTopOfScale(getValue(SigRangeHi));}
            else{
                io_Voltage->setElecTopOfScale(10);}
            
            if(!EngRangeHi || !EngRangeLow || !SigRangeLow || !SigRangeHi){
                blank->setNote("VALUE OF RANGE NOT KNOWN");
            }

            io_Voltage->setChannel(channel);
            blank->~IO_Object();
            return io_Voltage;
            
        }

        
    }
    else if (digitalOutput|| AnalogOutput){
        if (digitalOutput) {
            OutputDigital* io_Digital = new OutputDigital(SoftwareTag);
            io_Digital->setChannel(channel);
            blank->~IO_Object();
            return io_Digital;
        }
        
        else if (AnalogOutput){
            OutputVoltage* io_Voltage = new OutputVoltage(SoftwareTag);
            int i = 0;
            i = getUnit(EngRangeLow);
            // cout << i<<"\n";
            if(i != 0){
                io_Voltage->setEngScaleUnit(i);}
            else{
                io_Voltage->setEngScaleUnit(i);

                }
            io_Voltage->setElecBottomOfScale(getValue(SigRangeLow));
            io_Voltage->setElecTopOfScale(getValue(SigRangeHi));
            io_Voltage->setChannel(channel);
            io_Voltage->setEngBottomOfScale(getValue(EngRangeLow));
            io_Voltage->setEngTopOfScale(getValue(EngRangeHi));
            io_Voltage->setOffset(0);
            blank->~IO_Object();
            return io_Voltage;
            
        }
        
    }
    return blank;
}
B3_Object* RowHolder::b3createPoint(int channelIn){
    int channel = channelIn;
    //cout<<type<<"\n"<<flush;
    char* temp{NULL};
    if(PointType) temp =strstr (PointType,"Thermistor");
    char* input = strstr (Point,"I");
    char* universalInput = NULL;
    char* digitalInput = NULL;
    char* digitalOutput = NULL;
    char* AnalogInput = NULL;
    char* AnalogOutput = NULL;
    if(ConnectionType) {
        universalInput =strstr (ConnectionType,"UI");
        digitalInput =strstr (ConnectionType,"DI");
        digitalOutput = strstr (ConnectionType,"DO");
        AnalogInput =strstr (ConnectionType,"AI");
        AnalogOutput = strstr (ConnectionType,"AO");
    }
    else{
        
        digitalOutput = strstr (Point,"NC");
        if(!digitalOutput) digitalOutput = strstr (Point,"NO");
        AnalogOutput = strstr (Point,"AO");
    };
    
    if(digitalInput|| AnalogInput || universalInput){
        
        if(temp){
            B3_input_Analog* blank = new B3_input_Analog(SoftwareTag);
            blank->setChannel(channel);
            //hard coded thermistor Type1 (continuum)
            blank->setElectricType(3);
            return blank;}
        else if (digitalInput){
            B3_input_Digital* b3_Digital = new B3_input_Digital(SoftwareTag);
            b3_Digital->setInactiveText(offValue);
            b3_Digital->setActiveText(onValue);
            b3_Digital->setChannel(channel);
            return b3_Digital;}
        else {
            B3_input_Analog* blank = new B3_input_Analog(SoftwareTag);
            
            blank->setChannel(channel);
            if(EngRangeHi){
                blank->setEngScaleUnit(getUnit(EngRangeHi));
                blank->setEngTopOfScale(getValue(EngRangeHi));}
            
            else{
                blank->setEngTopOfScale(100);
                blank->setEngScaleUnit(0);}
            if(EngRangeLow){
                blank->setEngBottomOfScale(getValue(EngRangeLow));}
            else{
                blank->setEngBottomOfScale(0);}
            
            if(SigRangeLow){
                blank->setElecBottomOfScale(getValue(SigRangeLow));}
            else{
                blank->setElecBottomOfScale(0);}
            
            if(SigRangeHi){
                blank->setElecTopOfScale(getValue(SigRangeHi));}
            else{
                blank->setElecTopOfScale(10);}
            
            if(!EngRangeHi || !EngRangeLow || !SigRangeLow || !SigRangeHi){
                blank->setNote("VALUE OF RANGE NOT KNOWN");
            }
            
            blank->setOffset(0);
            return blank;
            
        }
    }
    else if (digitalOutput|| AnalogOutput){
        if (digitalOutput){
            B3_OutputDigital* b3_Digital_output = new B3_OutputDigital(SoftwareTag);
            b3_Digital_output->setActiveText(onValue);
            b3_Digital_output->setInactiveText(offValue);
            b3_Digital_output->setChannel(channel);
            return b3_Digital_output;
        }
        if(AnalogOutput){
            B3_output_Analog* B3_analog_Output = new B3_output_Analog(SoftwareTag);
            B3_analog_Output->setChannel(channel);
            if(EngRangeHi){
                B3_analog_Output->setEngScaleUnit(getUnit(EngRangeHi));
                B3_analog_Output->setEngTopOfScale(getValue(EngRangeHi));}
            
            else{
                B3_analog_Output->setEngTopOfScale(100);
                B3_analog_Output->setEngScaleUnit(0);}
            if(EngRangeLow){
                B3_analog_Output->setEngBottomOfScale(getValue(EngRangeLow));}
            else{
                B3_analog_Output->setEngBottomOfScale(0);}
            
            if(SigRangeLow){
                B3_analog_Output->setElecBottomOfScale(getValue(SigRangeLow));}
            else{
                B3_analog_Output->setElecBottomOfScale(0);}
            
            if(SigRangeHi){
                B3_analog_Output->setElecTopOfScale(getValue(SigRangeHi));}
            else{
                B3_analog_Output->setElecTopOfScale(10);}
            
            if(!EngRangeHi || !EngRangeLow || !SigRangeLow || !SigRangeHi){
                B3_analog_Output->setNote("VALUE OF RANGE NOT KNOWN");
            }
            
            B3_analog_Output->setChannel(channel);
            
            return B3_analog_Output;
            
        }
    }
    //B3_Object* blanks = new B3_Object();
    
    return NULL;
    
}