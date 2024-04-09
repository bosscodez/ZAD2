#include "temperature_sensor_mock.h"
#include "../PRODUKCYJNY/valve_controller.h"
#include <vector>
#include <iostream>

void testingMethod(std::vector<int> dataSet, std::vector<bool> expectedPosition, ValveController &valveController, MCKTemperatureSensor &tempSensor) {
        for (unsigned int i = 0; i < 7; i++)
        {
            bool result = valveController.openValve();
            std::cout << "Pozycja: " << i + 1 << std::endl;
            std::cout << "Oczekiwana wartosc: " << expectedPosition[i] << ". Otrzymano: " << result << std::endl;
            if (result != expectedPosition[i])
            {
                std::cout << "niepowodzenie" << std::endl;
            }
            else {
                std::cout << "powodzenie." << std::endl;
            }
            std::cout << std::endl;
        }
        tempSensor.resetState();
}

int main()
{
    MCKTemperatureSensor tempSensor;
    ValveController valveController;
    valveController.setTempSensor(&tempSensor);
    valveController.setExpectedTemp(20);

    std::cout << "TEST Z PIERWSZYM ZESTAWEM DANYCH" << std::endl;
    std::vector<int> dataSet = { 19, 20, 20, 21, 20, 20, 19 };
    std::vector<bool> expectedPosition = { true, true, true, false, false, false, true };
    tempSensor.setTemperatures(dataSet);
    testingMethod(dataSet, expectedPosition, valveController, tempSensor);

    std::cout << "TEST Z DRUGIM ZESTAWEM DANYCH" << std::endl;
    dataSet = { 18, 19, 20, 21, 20, 20, 19 };
    expectedPosition = { true, true, true, false, false, false, true };
    tempSensor.setTemperatures(dataSet);
    testingMethod(dataSet, expectedPosition, valveController, tempSensor);

    return 0;
}
