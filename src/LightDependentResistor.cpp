#include "LightDependentResistor.h"

LightDependentResistor::LightDependentResistor(){
    Setup();
}

LightDependentResistor::LightDependentResistor(uint8_t pin){
    Setup(pin);
}

LightDependentResistor::LightDependentResistor(uint8_t pin, void (*onValueChanged)(bool)){
    Setup(pin, onValueChanged);
}

LightDependentResistor::~LightDependentResistor(){
    ValueChanged.Clear();
}

void LightDependentResistor::Setup(){
    SetPin(0);
    ValueChanged.Clear();
    _value = false;
}

void LightDependentResistor::Setup(uint8_t pin){
    Setup();
    SetPin(pin);
}

void LightDependentResistor::Setup(uint8_t pin, void (*onValueChanged)(bool)){
    Setup();
    SetPin(pin);
    ValueChanged.Add(onValueChanged);
}

void LightDependentResistor::SetPin(uint8_t pin){
    _pin = pin;
}

uint8_t LightDependentResistor::GetPin(){
    return _pin;
}

bool LightDependentResistor::GetValue(){
    return _value;
}

bool LightDependentResistor::Read(){
    bool current = digitalRead(_pin)==HIGH? false: true;
    if( current != _value ){
        _value = current;
        ValueChanged.Invoke(current);
    }
    return current;
}