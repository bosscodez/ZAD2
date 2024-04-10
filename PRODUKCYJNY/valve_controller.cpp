#include "../PRODUKCYJNY/valve_controller.h"

void ValveController::setTempSensor(ITemperatureSensor* tempSensor)
{
	this->tempSensor = tempSensor;
}

void ValveController::setExpectedTemp(int expectedTemp)
{
	this->expectedTemp = expectedTemp;
}

bool ValveController::openValve()
{
	int currentTemperature = this->tempSensor->getTemperature();
	if (currentTemperature < this->expectedTemp) {
		this->lastState = true;
		return true;
	}
	else if (currentTemperature > this->expectedTemp) {
		this->lastState = false;
		return false;
	}
	else {
		return this->lastState;
	}
}