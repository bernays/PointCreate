//
//  B3_Input.cpp
//  IO_Export
//
//  Created by Benjamin Bernays on 6/17/15.
//
//
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "B3_Input.h"
using namespace std;
B3_input_Analog::B3_input_Analog(){
    channel = NULL;
    name = NULL;
}
B3_input_Analog:: B3_input_Analog(char * nameIn){
    channel = NULL;
    name = nameIn;
    //cout<< "    IO_Object " <<nameIn << "default voltage constructed." << endl;
    
}
void B3_input_Analog::writeSelf(){
    //cout <<"Analog point channel: "<<channel<<".\n";
    
    cout <<"    <OI DESCR=\"\" NAME=\"" << name<<"\" TYPE=\"bacnet.b3.point.analog.Input\">\n";
    cout <<"      <PI Name=\"AlarmMessage\" Value=\"\" />\n";
    cout <<"      <PI Name=\"BACnetName\" Value=\""<< name <<"\" />\n";
    cout <<"      <PI Name=\"COVIncrement\" Value=\"0.5\" />\n";
    cout <<"      <PI Name=\"Channel\" Value=\""<<channel <<"\" />\n";
    cout <<"      <PI Name=\"Deadband\" Value=\"0\" />\n";
    cout <<"      <PI Name=\"DeviceType\" Value=\"\" />\n";
    cout <<"      <PI Name=\"ElectricType\" Value=\""<<ElectricType<<"\" />\n";
    cout <<"      <PI Name=\"EventEnable\" Value=\"0\" />\n";
    cout <<"      <PI Name=\"FaultMessage\" Value=\"\" />\n";
    cout <<"      <PI Name=\"ForeignAddress\" Value=\"\" />\n";
    cout <<"      <PI Name=\"HighLimit\" Value=\"0\" />\n";
    cout <<"      <PI Name=\"LimitEnable\" Value=\"0\" />\n";
    cout <<"      <PI Name=\"LogInterval\" Value=\"900\" />\n";
    cout <<"      <PI Name=\"LogSize\" Value=\"96\" />\n";
    cout <<"      <PI Name=\"LogType\" Value=\"2\" />\n";
    cout <<"      <PI Name=\"LowLimit\" Value=\"0\" />\n";
    cout <<"      <PI Name=\"MaxPresValue\" Value=\"0\" />\n";
    cout <<"      <PI Name=\"MinPresValue\" Value=\"0\" />\n";
    if(Note){
        cout <<"      <PI Name=\"NOTE1\" Value=\""<<Note<<"\" />\n";}
    cout <<"      <PI Name=\"NotificationClass\" RefNull=\"1\" />\n";
    cout <<"      <PI Name=\"NotifyType\" Value=\"0\" />\n";
    cout <<"      <PI Name=\"ProfileName\" Value=\"\" />\n";
    cout <<"      <PI Name=\"ResetMessage\" Value=\"\" />\n";
    cout <<"      <PI Name=\"Resolution\" Value=\"0\" />\n";
    cout <<"      <PI Name=\"Threshold\" Value=\"0.5\" />\n";
    cout <<"      <PI Name=\"TimeDelay\" Value=\"0\" />\n";
    cout <<"      <PI Name=\"UpdateInterval\" Value=\"0\" />\n";
    cout <<"      <PI Name=\"Value\" RefNull=\"1\" Unit=\"0x"<<hex << EngScaleUnit <<dec<<"\" />\n";
    cout <<"    </OI>\n";

}

void B3_input_Analog::setElectricType(int inElecType){
    ElectricType =inElecType;
}
void B3_input_Analog::setCOVIncrement(int inCOV){
    COVIncrement = inCOV;
}
int B3_input_Analog::getElectricType(){
    return ElectricType;
}
int B3_input_Analog::getCOVIncrement(){
    return COVIncrement;
}

void B3_input_Analog::setOffset(int inOffset){
    Offset = inOffset;
}
void B3_input_Analog::setElecBottomOfScale(int inElecBottomOfScale){
    ElecBottomOfScale = inElecBottomOfScale;
}
void B3_input_Analog::setElecTopOfScale(int inElecTopOfScale){
    ElecTopOfScale = inElecTopOfScale;
}
void B3_input_Analog::setEngBottomOfScale(int inEngBottomOfScale){
    EngBottomOfScale = inEngBottomOfScale;
}
void B3_input_Analog::setEngTopOfScale(int inEngTopOfScale){
    EngTopOfScale = inEngTopOfScale;
}
void B3_input_Analog::setLogArray(int inLogArray){
    LogArray = inLogArray;
}
void B3_input_Analog::setThreshold(int inThreshold){
    Threshold = inThreshold;
}
void B3_input_Analog::setValue(int inValue){
    Value = inValue;
}
void B3_input_Analog::setEngScaleUnit(int inEngScaleUnit){
    EngScaleUnit = inEngScaleUnit;
}
void B3_input_Analog::setElecUnit(int inElecUnit){
    ElecUnit = inElecUnit;
}

B3_input_Digital::B3_input_Digital(){
    channel = NULL;
    name = NULL;
}
B3_input_Digital:: B3_input_Digital(char * nameIn){
    channel = NULL;
    name = nameIn;
    //cout<< "    IO_Object " <<nameIn << "default Digital constructed." << endl;
    
}
void B3_input_Digital::setActiveText(char* activeText){
    ActiveText = activeText;
}
void B3_input_Digital::setInactiveText(char* inactiveText){
    InactiveText = inactiveText;
}
void B3_input_Digital::writeSelf(){
   //cout <<"Digital point channel: "<<channel<<".\n";
    
    cout <<"    <OI DESCR=\"\" NAME=\"" << name<<"\" TYPE=\"bacnet.b3.point.digital.Input\">\n";
    if(ActiveText){
        cout<< "      <PI Name=\"ActiveText\" Value=\""<<ActiveText<<"\" />\n";}
    else{
        cout<< "      <PI Name=\"ActiveText\" Value=\"\" />\n";}
    cout <<"      <PI Name=\"AlarmMessage\" Value=\"\" />\n";
    cout <<"      <PI Name=\"AlarmValue\" Value=\"0\" />\n";
    cout <<"      <PI Name=\"ChangeOfStateCount\" RefNull=\"1\" />\n";
    cout <<"      <PI Name=\"ChangeOfStateTime\" RefNull=\"1\" />\n";
    cout <<"      <PI Name=\"Channel\" Value=\""<<channel <<"\" />\n";
    cout <<"      <PI Name=\"DeviceType\" Value=\"\" />\n";
    cout <<"      <PI Name=\"ElapsedActiveTime\" RefNull=\"1\" />\n";
    cout <<"      <PI Name=\"EventEnable\" Value=\"0\" />\n";
    cout <<"      <PI Name=\"FaultMessage\" Value=\"\" />\n";
    cout <<"      <PI Name=\"ForeignAddress\" Value=\"\" />\n";
    if(InactiveText){
        cout<< "      <PI Name=\"InactiveText\" Value=\""<<InactiveText<<"\" />\n";}
    else{
        cout<< "      <PI Name=\"InactiveText\" Value=\"\" />\n";}
    cout <<"      <PI Name=\"LogInterval\" Value=\"900\" />\n";
    cout <<"      <PI Name=\"LogSize\" Value=\"96\" />\n";
    cout <<"      <PI Name=\"LogType\" Value=\"2\" />\n";
    if(Note){
        cout <<"      <PI Name=\"NOTE1\" Value=\""<<Note<<"\" />\n";}
    cout <<"      <PI Name=\"NotificationClass\" RefNull=\"1\" />\n";
    cout <<"      <PI Name=\"NotifyType\" Value=\"0\" />\n";
    cout <<"      <PI Name=\"ProfileName\" Value=\"\" />\n";
    cout <<"      <PI Name=\"ResetMessage\" Value=\"\" />\n";
    cout <<"      <PI Name=\"TimeDelay\" Value=\"0\" />\n";
    cout <<"      <PI Name=\"TimeOfActiveTimeReset\" RefNull=\"1\" />\n";
    cout <<"      <PI Name=\"TimeOfStateCountReset\" RefNull=\"1\" />\n";
    cout <<"    </OI>\n";
}