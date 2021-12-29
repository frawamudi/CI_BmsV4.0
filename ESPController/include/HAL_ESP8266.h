/*
THIS IS THE HARDWARE ABSTRACT LAYER 
FOR DIYBMS ESP8265 CONTROLLER PCB - THIS IS THE SMALLER
PCB WITH INTERFACE FOR EXTERNAL RELAY BOARD USING PCF8574
I2C I/O EXPANDER
*/
#if defined(ESP8266)


#include <Arduino.h>
#include <Wire.h>



#define RESET_WIFI_PIN D3
#define PFC_INTERRUPT_PIN D5
#define GREEN_LED D0

//defining new outpins 
#ifdef MY_VERSION_1_0
//#define FOR_OUTPUT //comment or uncomment this macr to use D6 as output or input
#define CURRENT_SENSENING A0 //analogue pin for current sensing
#define MY_IO_PIN D6
#endif

//Debug flags for ntpclientlib
#define DBG_PORT Serial1
//#define DEBUG_NTPCLIENT

#define GREEN_LED_ON hal.GreenLedOn()
#define GREEN_LED_OFF hal.GreenLedOff()

#ifndef HAL_ESP8266_H_
#define HAL_ESP8266_H_

// Derived classes
class HAL_ESP8266
{
public:
    void ConfigureI2C(void (*ExternalInputInterrupt)(void));
    void SetOutputState(uint8_t outputId, RelayState state);
    #ifdef MY_VERSION_1_0
    void WriteToPortExpander(uint8_t testID, uint8_t state);
    #endif
    uint8_t ReadInputRegisters();
    float ReadCurrentSensor();
    bool OutputsEnabled = false;
    bool InputsEnabled = false;
    void ConfigurePins();

void GreenLedOn() {
    digitalWrite(GREEN_LED, HIGH);
}
void GreenLedOff() {
    digitalWrite(GREEN_LED, LOW);
}



private:
    //Private constructor (static class)
};

#endif

#endif