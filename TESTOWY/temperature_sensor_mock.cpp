#include "temperature_sensor_mock.h"
#include <vector>

void MCKTemperatureSensor::setTemperatures(std::vector<int> testTemp) {
	this->i = 0;
	this->testTemperatures.clear();
	this->testTemperatures = testTemp;
}

int MCKTemperatureSensor::getTemperature() {
	return this->testTemperatures[i++];
}