#ifndef VALVE_CONTROLLER_IF_H
#define VALVE_CONTROLLER_IF_H

#include "temperature_sensor_if.h"

class IValveController
{
public:
    virtual void setTempSensor(ITemperatureSensor* temperatureSensor) = 0;
    virtual void setExpectedTemp(int expectedTemp) = 0;
    virtual bool openValve() = 0;
};

#endif // VALVE_CONTROLLER_IF_H

