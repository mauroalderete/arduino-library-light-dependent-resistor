#ifndef _LIGHTDEPENDENTRESISTOR_HPP_
#define _LIGHTDEPENDENTRESISTOR_HPP_

#include <Arduino.h>
#include <EventHandler.h>

class LightDependentResistor{
    private:
        uint8_t _pin;
        bool _value;

    public:
        EventHandler<bool> Changed;

        LightDependentResistor();
        LightDependentResistor(uint8_t pin);
        LightDependentResistor(uint8_t pin, void (*onChanged)(bool));
        ~LightDependentResistor();

        void Setup();
        void Setup(uint8_t pin);
        void Setup(uint8_t pin, void (*onChanged)(bool));

        void SetPin(uint8_t pin);
        uint8_t GetPin();
        
        bool GetValue();

        bool Read();
};

#endif