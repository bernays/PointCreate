//
//  IO_Object_Output.cpp
//  IO_Export
//
//  Created by Benjamin Bernays on 5/22/15.
//
//

#include "IO_Output.h"
OutputVoltage::OutputVoltage(){
    channel = NULL;
    name = NULL;
}
OutputVoltage:: OutputVoltage(char * nameIn){
    channel = NULL;
    name = nameIn;
    //cout<< "    IO_Object " <<nameIn << "default voltage constructed." << endl;
    
}
void OutputVoltage::writeSelf(){
    
    cout <<"<OI NAME=\""<< name<<"\" TYPE=\"io.point.VoltageOutput\">\n";
    cout <<"  <PI Name=\"DefaultOutput\" Unit=\""<<hex << EngScaleUnit<<dec <<"\" Value=\"0\" />\n";
    cout <<"  <PI Name=\"ElecBottomOfScale\" Value=\""<<ElecBottomOfScale <<"\"/> \n";
    cout <<"  <PI Name=\"ElecTopOfScale\" Value=\""<<ElecTopOfScale <<"\"/> \n";
    cout <<"  <PI Name=\"EngTopOfScale\" Unit=\"0x"<<hex << EngScaleUnit <<"\" Value=\""<<dec<<EngTopOfScale<<"\" />\n";
    cout <<"  <PI Name=\"OutputChannelNumber\" Value=\""<<channel <<"\"/> \n";
    cout <<"  <PI Name=\"EngBottomOfScale\" Unit=\"0x"<<hex << EngScaleUnit <<"\" Value=\""<<dec<<EngBottomOfScale<<"\" />\n";
    cout <<"  <PI Name=\"LogArray\" RefNull=\"1\" Unit=\"0x"<<hex << EngScaleUnit<<"\" />\n";
    cout <<"  <PI Name=\"Offset\" Unit=\"0x"<<hex << EngScaleUnit <<"\" Value=\""<<dec<<Offset<<"\" />\n";
    cout <<"  <PI Name=\"RequestedValue\" Value=\""<<ElecBottomOfScale <<"\"/> \n";
    cout <<"  <PI Name=\"Value\" RefNull=\"1\" Unit=\"0x"<<hex << EngScaleUnit <<dec<<"\" />\n";
    cout <<"</OI>\n";
}

void OutputVoltage::setOffset(int inOffset){
    Offset = inOffset;
}
void OutputVoltage::setElecBottomOfScale(int inElecBottomOfScale){
    ElecBottomOfScale = inElecBottomOfScale;
}
void OutputVoltage::setElecTopOfScale(int inElecTopOfScale){
    ElecTopOfScale = inElecTopOfScale;
}
void OutputVoltage::setEngBottomOfScale(int inEngBottomOfScale){
    EngBottomOfScale = inEngBottomOfScale;
}
void OutputVoltage::setEngTopOfScale(int inEngTopOfScale){
    EngTopOfScale = inEngTopOfScale;
}
void OutputVoltage::setLogArray(int inLogArray){
    LogArray = inLogArray;
}
void OutputVoltage::setThreshold(int inThreshold){
    Threshold = inThreshold;
}
void OutputVoltage::setValue(int inValue){
    Value = inValue;
}
void OutputVoltage::setEngScaleUnit(int inEngScaleUnit){
    EngScaleUnit = inEngScaleUnit;
}
void OutputVoltage::setElecUnit(int inElecUnit){
    ElecUnit = inElecUnit;
}
void OutputVoltage::setRequestedValue(int inrequestedValue){
    requestedValue = inrequestedValue;
}

OutputDigital::OutputDigital(){
    channel = NULL;
    name = NULL;
}
OutputDigital:: OutputDigital(char * nameIn){
    channel = NULL;
    name = nameIn;
    //cout<< "    IO_Object " <<nameIn << "default Digital constructed." << endl;
    
}
void OutputDigital::writeSelf(){
    
    cout <<"<OI NAME=\""<< name<<"\" TYPE=\"io.point.DigitalOutput\">\n";
    cout <<"  <PI Name=\"OutputChannelNumber\" Value=\""<<dec <<channel <<"\"/> \n";
    cout <<"</OI>\n";
}

