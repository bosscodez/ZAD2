#ifndef VALVE_CONTROLLER_H
#define VALVE_CONTROLLER_H

#include "valve_controller_if.h"

class ValveController : public IValveController
{
public:
    virtual void setTempSensor(ITemperatureSensor* temperatureSensor) override;
    virtual void setExpectedTemp(int expectedTemp) override;
    virtual bool openValve() override;
private:
    ITemperatureSensor* tempSensor_ = nullptr;
    int expectedTemp_;
    bool lastState_;
};

#endif // VALVE_CONTROLLER_IF_H