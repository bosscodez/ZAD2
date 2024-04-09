#ifndef TEMPERATURE_SENSOR_IF_H
#define TEMPERATURE_SENSOR_IF_H

class ITemperatureSensor
{
public:
    virtual int getTemperature() = 0;
};

#endif // TEMPERATURE_SENSOR_IF_H