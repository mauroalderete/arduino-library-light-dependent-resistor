#include <Arduino.h>
#include <LightDependentResistor.h>
#include <Lolin3.h>

LightDependentResistor ldr;

void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.print("Start");
  ldr.Setup(D2, ldrChanged);
}

void loop() {
  delay(500);
  ldr.Read();
  if ( ldr.GetValue() ){
    Serial.print("+");
  } else {
    Serial.print("-");
  }
}

void ldrChanged(bool value){
  if( value ){
    Serial.println("LDR: Encendido");
  }else {
    Serial.println("LDR: Apagado");
  }
}
