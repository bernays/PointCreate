//
//  IO_Object_Input.cpp
//  IO_Export
//
//  Created by Benjamin Bernays on 5/22/15.
//
//

#include "IO_Input.h"
InputVoltage::InputVoltage(){
    channel = NULL;
    name = NULL;
}
InputVoltage:: InputVoltage(char * nameIn){
    channel = NULL;
    name = nameIn;
    //cout<< "    IO_Object " <<nameIn << "default voltage constructed." << endl;
    
}
void InputVoltage::writeSelf(){
    
    cout <<"<OI NAME=\""<< name<<"\" TYPE=\"io.point.VoltageInput\">\n";
    cout <<"  <PI Name=\"ElecBottomOfScale\" Value=\""<<ElecBottomOfScale <<"\"/> \n";
    cout <<"  <PI Name=\"ElecTopOfScale\" Value=\""<<ElecTopOfScale <<"\"/> \n";
    cout <<"  <PI Name=\"EngTopOfScale\" Unit=\"0x"<<hex << EngScaleUnit <<"\" Value=\""<<dec<<EngTopOfScale<<"\" />\n";
    cout <<"  <PI Name=\"InputChannelNumber\" Value=\""<<channel <<"\"/> \n";
    cout <<"  <PI Name=\"EngBottomOfScale\" Unit=\"0x"<<hex << EngScaleUnit <<"\" Value=\""<<dec<<EngBottomOfScale<<"\" />\n";
    cout <<"  <PI Name=\"LogArray\" RefNull=\"1\" Unit=\"0x"<<hex << EngScaleUnit<<"\" />\n";
    cout <<"  <PI Name=\"Offset\" Unit=\"0x"<<hex << EngScaleUnit <<"\" Value=\"0\" />\n";
    cout <<"  <PI Name=\"Value\" RefNull=\"1\" Unit=\"0x"<<hex << EngScaleUnit <<dec<<"\" />\n";
    cout <<"</OI>\n";
}

void InputVoltage::setElecBottomOfScale(int inElecBottomOfScale){
    ElecBottomOfScale = inElecBottomOfScale;
}
void InputVoltage::setElecTopOfScale(int inElecTopOfScale){
    ElecTopOfScale = inElecTopOfScale;
}
void InputVoltage::setEngBottomOfScale(int inEngBottomOfScale){
    EngBottomOfScale = inEngBottomOfScale;
}
void InputVoltage::setEngTopOfScale(int inEngTopOfScale){
    EngTopOfScale = inEngTopOfScale;
}
void InputVoltage::setValue(int inValue){
    Value = inValue;
}
void InputVoltage::setEngScaleUnit(int inEngScaleUnit){
    EngScaleUnit = inEngScaleUnit;
}
void InputVoltage::setElecUnit(int inElecUnit){
    ElecUnit = inElecUnit;
}

InputDigital::InputDigital(){
    channel = NULL;
    name = NULL;
}
InputDigital:: InputDigital(char * nameIn){
    channel = NULL;
    name = nameIn;
    //cout<< "    IO_Object " <<nameIn << "default Digital constructed." << endl;
    
}
void InputDigital::writeSelf(){
    
    cout <<"<OI NAME=\""<< name<<"\" TYPE=\"io.point.DigitalInput\">\n";
    cout <<"  <PI Name=\"InputChannelNumber\" Value=\""<<dec <<channel <<"\"/> \n";
    cout <<"</OI>\n";
}

InputTemperature::InputTemperature(){
    channel = NULL;
    name = NULL;
}
InputTemperature:: InputTemperature(char * nameIn){
    channel = NULL;
    name = nameIn;
    //cout<< "    InputTemperature " <<nameIn << "default voltage constructed." << endl;
}
void InputTemperature::setThermistor(int therm){
    Thermistor = therm;
}
int InputTemperature::getThermistor(){
    return Thermistor;
}
void InputTemperature::writeSelf(){
    
    cout <<"<OI NAME=\""<< name<<"\" TYPE=\"io.point.TemperatureInput\">\n";
    cout <<"  <PI Name=\"InputChannelNumber\" Value=\""<<dec <<channel <<"\"/> \n";
     cout <<"  <PI Name=\"ThermistorType\" Value=\""<<dec<<Thermistor <<"\"/> \n";
    cout <<"</OI>\n";
}




