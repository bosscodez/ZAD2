#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "temperature_sensor_if.h"
#include "vector"

class UTTemperatureSensor : public ITemperatureSensor
{
public:
    int getTemperature() override;
private:
    std::vector<int> testTemperatures;
    int i = 0;
};

#endif //TEMPERATURE_SENSOR_H