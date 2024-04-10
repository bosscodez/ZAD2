#include "temperature_sensor_mock.h"
#include "../PRODUKCYJNY/valve_controller.h"
#include <vector>
#include <iostream>

void testingMethod(const std::vector<std::vector<int>>& dataSets, const std::vector<std::vector<bool>>& expectedPositions, ValveController& valveController, MCKTemperatureSensor& tempSensor) {
    for (unsigned int j = 0; j < dataSets.size(); ++j) {
        const auto& dataSet = dataSets[j];
        const auto& expectedPosition = expectedPositions[j];

        tempSensor.setTemperatures(dataSet);
        std::cout << "ZESTAW DANYCH " << j + 1 << std::endl;
        for (unsigned int i = 0; i < dataSet.size(); ++i) {
            bool result = valveController.openValve();
            std::cout << "Pozycja: " << i + 1 << std::endl;
            std::cout << "Oczekiwana wartosc: " << expectedPosition[i] << ". Otrzymano: " << result << std::endl;
            if (result != expectedPosition[i]) {
                std::cout << "niepowodzenie" << std::endl;
            }
            else {
                std::cout << "powodzenie." << std::endl;
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    MCKTemperatureSensor tempSensor;
    ValveController valveController;
    valveController.setTempSensor(&tempSensor);

    std::vector<std::vector<int>> dataSets20 = {
        {19, 20, 20, 21, 20, 20, 19},
        {18, 19, 20, 21, 20, 20, 19}
    };

    std::vector<std::vector<bool>> expectedPositions20 = {
        {true, true, true, false, false, false, true},
        {true, true, true, false, false, false, true}
    };

    std::vector<std::vector<int>> dataSets25 = {
        {24, 25, 26, 27, 26, 25, 24},
        {23, 24, 25, 26, 25, 24, 23}
    };

    std::vector<std::vector<bool>> expectedPositions25 = {
        {true, true, false, false, false, false, true},
        {true, true, true, false, false, true, true}
    };

    std::cout << "TESTY DLA OCZEKIWANEJ TEMPERATURY 20: " << std::endl;
    valveController.setExpectedTemp(20);
    testingMethod(dataSets20, expectedPositions20, valveController, tempSensor);

    std::cout << "TESTY DLA OCZEKIWANEJ TEMPERATURY 25: " << std::endl;
    valveController.setExpectedTemp(25);
    testingMethod(dataSets25, expectedPositions25, valveController, tempSensor);

    return 0;
}
