#ifndef _LIGHTDEPENDENTRESISTOR_HPP_
#define _LIGHTDEPENDENTRESISTOR_HPP_

#include <Arduino.h>
#include <EventHandler.h>

/**
* @brief Simplifica la interacción con un sensor LDR en modo ditigal
* */
class LightDependentResistor{
    private:
        uint8_t _pin;
        bool _value;

    public:
        /**
        * @brief Evento que se dispara cuando se detecta un cambio de estado luego de ejecutar Read()
        * */
        EventHandler<bool> ValueChanged;

        /**
        * @brief Instancia e inicializa el objeto sin valores configurados
        * */
        LightDependentResistor();
        /**
        * @brief Instancia e inicializa el objeto con un pin, pero sin callback
        * @param uint8_t Pin al que esta conectado el sensor LDR
        * */
        LightDependentResistor(uint8_t pin);
        /**
        * @brief Instancia e inicializa el objeto con un pin y un callback asociado al evento ValueChanged
        * @param uint8_t Pin al que esta conectado el sensor LDR
        * @param void (*onValueChanged)(bool) Callback que se invocara cuando se detecte un cambio de estado durante la ejecución de Read()
        * */
        LightDependentResistor(uint8_t pin, void (*onValueChanged)(bool));
        /**
        * @brief Destruye toda referencia al evento ValueChanged
        * */
        ~LightDependentResistor();

        /**
        * @brief Inicializa el objeto sin valores configurados
        * */
        void Setup();
        /**
        * @brief Inicializa el objeto con un pin, pero sin callback
        * @param uint8_t Pin al que esta conectado el sensor LDR
        * */
        void Setup(uint8_t pin);
        /**
        * @brief Inicializa el objeto con un pin y un callback asociado al evento ValueChanged
        * @param uint8_t Pin al que esta conectado el sensor LDR
        * @param void (*onValueChanged)(bool) Callback que se invocara cuando se detecte un cambio de estado durante la ejecución de Read()
        * */
        void Setup(uint8_t pin, void (*onValueChanged)(bool));

        /**
        * @brief Cambia el pin de lectura
        * @param uint8_t Pin al que esta conectado el sensor LDR
        * */
        void SetPin(uint8_t pin);
        /**
        * @brief Devuelve el pin de lectura actual
        * */
        uint8_t GetPin();
        
        /**
        * @brief Devuelve el ultimo valor leido
        * */
        bool GetValue();

        /**
        * @brief Lee y devuelve el estado actual del LDR, si hubo un cambio dispara el evento ValueChanged
        * */
        bool Read();
};

#endif