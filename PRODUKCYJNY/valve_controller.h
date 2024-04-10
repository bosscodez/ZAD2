#ifndef VALVE_CONTROLLER_H
#define VALVE_CONTROLLER_H

#include "valve_controller_if.h"

class ValveController : public IValveController
{
public:
    virtual void setTempSensor(ITemperatureSensor* tempSensor) override;
    virtual void setExpectedTemp(int expectedTemp) override;
    virtual bool openValve() override;
private:
    ITemperatureSensor* tempSensor = nullptr;
    int expectedTemp;
    bool lastState;
};

#endif // VALVE_CONTROLLER_IF_H