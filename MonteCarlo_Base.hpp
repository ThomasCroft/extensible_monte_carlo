#pragma once

#include <random>

template <class RandomType>
class MonteCarlo
{
public:
  MonteCarlo() : result(0), rd(), mt(rd()) {};
  virtual ~MonteCarlo() = default;

  double simulate(unsigned int num_iterations)
  {
    for(unsigned int i = 1; i <= num_iterations; ++i)
      iterate(i);

    return result;
  }

private:
  void iterate(unsigned int iteration)
  {
    auto value = createRandomValue();
    result *= (iteration - 1) / static_cast<double>(iteration);
    result += static_cast<double>(value) / iteration;
  }

  double result;
  virtual RandomType createRandomValue() = 0;

  std::random_device rd;

protected:
  std::mt19937 mt;
};
