#include "LightDependentResistor.h"

LightDependentResistor::LightDependentResistor(){
    Setup();
}

LightDependentResistor::LightDependentResistor(uint8_t pin){
    Setup(pin);
}

LightDependentResistor::LightDependentResistor(uint8_t pin, void (*onChanged)(bool)){
    Setup(pin, onChanged);
}

LightDependentResistor::~LightDependentResistor(){
    Changed.Clear();
}

void LightDependentResistor::Setup(){
    SetPin(0);
    Changed.Clear();
    _value = false;
}

void LightDependentResistor::Setup(uint8_t pin){
    Setup();
    SetPin(pin);
}

void LightDependentResistor::Setup(uint8_t pin, void (*onChanged)(bool)){
    Setup();
    SetPin(pin);
    Changed.Add(onChanged);
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
        Changed.Invoke(current);
    }
    return current;
}