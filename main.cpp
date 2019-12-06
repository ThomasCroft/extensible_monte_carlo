#include <iostream>
#include "Calculators.h"

int main()
{
  PiCalculator pi_calculator{};
  std::cout << "pi     : " << pi_calculator.simulate(10000) << std::endl;

  EulersNumberCalculator eulers_number_calculator{};
  std::cout << "e      : " << eulers_number_calculator.simulate(10000) << std::endl;

  RootCalculator root_seven_calculator{7.0};
  std::cout << "root 7 : " << root_seven_calculator.simulate(10000) << std::endl;

  std::cout << "integration of" << std::endl;

  // definite integral = 16
  IntegrationCalculator y_equals_x_calculator{[](std::vector<double> input){return input[0];},
    IntegrationCalculator::RandomNumberRanges{std::pair<double, double>{7.0, 9.0}}};
  std::cout << "y = x between 7 and 9 : " << y_equals_x_calculator.simulate(10000) << std::endl;

  // definite integral = 221.67
  IntegrationCalculator y_equals_x_squared_calculator{[](std::vector<double> input){return input[0] * input[0];},
    IntegrationCalculator::RandomNumberRanges{std::pair<double, double>{4.0, 9.0}}};
  std::cout << "y = x^2 between 4 and 9 : " << y_equals_x_squared_calculator.simulate(10000) << std::endl;

  // definite integral = 5242
  IntegrationCalculator multi_dimension_integation_calculator{
    [](std::vector<double> input){return (input[1]*input[1]) + (2*input[0]*input[1]) + 16;},
        IntegrationCalculator::RandomNumberRanges{std::pair<double, double>{5.0, 9.0}, std::pair<double, double>{6.0, 12.0}}};
  std::cout << "y = z^2 + 2zx + 16 between x = 5, 9 and z = 6, 12 : "
            << multi_dimension_integation_calculator.simulate(100000) << std::endl;

  return 0;
}
