#ifndef TEMPERATURE_SENSOR_MOCK_H
#define TEMPERATURE_SENSOR_MOCK_H

#include "../produkcyjny/temperature_sensor_if.h"
#include "vector"

class MCKTemperatureSensor : public ITemperatureSensor
{
public:
    int getTemperature() override;
    void setTemperatures(std::vector<int>);
private:
    std::vector<int> testTemperatures;
    int i = 0;
};

#endif //TEMPERATURE_SENSOR_MOCK_H