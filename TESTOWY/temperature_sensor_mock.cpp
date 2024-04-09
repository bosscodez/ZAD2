#include "temperature_sensor_mock.h"
#include <vector>

void MCKTemperatureSensor::setTemperatures(std::vector<int> testTemp) {
	testTemperatures = testTemp;
}

int MCKTemperatureSensor::getTemperature() {
	return testTemperatures[i++];
}

void MCKTemperatureSensor::resetState() {
	i = 0;
	testTemperatures.clear();
}
