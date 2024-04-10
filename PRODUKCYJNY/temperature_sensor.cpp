#include "temperature_sensor.h"
#include <vector>

int UTTemperatureSensor::getTemperature() {
	return this->testTemperatures[i++];
}
