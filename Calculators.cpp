#include "Calculators.h"

// PiCalculator

PiCalculator::PiCalculator() :
  MonteCarlo(), random_coordinate(-1.0, 1.0)
{
}

unsigned int PiCalculator::createRandomValue()
{
  auto x = random_coordinate(mt);
  auto y = random_coordinate(mt);
  return ((x * x) + (y * y)) > 1 ? 0 : SQUARE_FACTOR;
}

// EulersNumberCalculator

EulersNumberCalculator::EulersNumberCalculator() :
  MonteCarlo(), random_number(0.0, 1.0)
{
}

unsigned int EulersNumberCalculator::createRandomValue()
{
  unsigned int i{0};
  for(double total = 0.0; total < 1; ++i)
    total += random_number(mt);

  return i;
}

// RootCalculator

RootCalculator::RootCalculator(const double original_number) :
    MonteCarlo(), m_original_number(original_number), random_number(0.0, m_original_number)
{
}

double RootCalculator::createRandomValue()
{
  auto x = random_number(mt);
  return x * x < m_original_number ? m_original_number : 0;
}

// IntegrationCalculator

IntegrationCalculator::IntegrationCalculator(FunctionHandler handler, RandomNumberRanges randomNumbers) :
  MonteCarlo(), m_function(handler), m_randomNumbers(), m_rangeFactor(1)
{
  for(RandomNumberRanges::iterator it = randomNumbers.begin(); it != randomNumbers.end(); ++it)
  {
    m_rangeFactor *= (*it).second - (*it).first;
    m_randomNumbers.emplace_back(std::uniform_real_distribution<double>{(*it).first, (*it).second});
  }
}

double IntegrationCalculator::createRandomValue()
{
  std::vector<double> inputVector;
  for(RandomNumbers::iterator it = m_randomNumbers.begin(); it != m_randomNumbers.end(); ++it)
  {
    inputVector.push_back((*it)(mt));
  }
  return m_rangeFactor * m_function(inputVector);
}

