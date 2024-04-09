#include "../PRODUKCYJNY/valve_controller.h"

void ValveController::setTempSensor(ITemperatureSensor* temperatureSensor)
{
	tempSensor_ = temperatureSensor;
}

void ValveController::setExpectedTemp(int expectedTemp)
{
	expectedTemp_ = expectedTemp;
}

bool ValveController::openValve()
{
	int currentTemperature = tempSensor_->getTemperature();
	if (currentTemperature < expectedTemp_) {
		lastState_ = true;
		return true;
	}
	else if (currentTemperature > expectedTemp_) {
		lastState_ = false;
		return false;
	}
	else {
		return lastState_;
	}
}