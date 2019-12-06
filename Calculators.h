#pragma once

#include <functional>

#include "MonteCarlo_Base.hpp"

class PiCalculator final : public MonteCarlo<unsigned int>
{
public:
  PiCalculator();
  ~PiCalculator() = default;

private:
  unsigned int createRandomValue() override;

  std::uniform_real_distribution<double> random_coordinate;
  static constexpr unsigned int SQUARE_FACTOR = 4;
};

class EulersNumberCalculator : public MonteCarlo<unsigned int>
{
public:
  EulersNumberCalculator();
  ~EulersNumberCalculator() = default;

private:
  unsigned int createRandomValue() override;

  std::uniform_real_distribution<double> random_number;
};

class RootCalculator : public MonteCarlo<double>
{
public:
  RootCalculator(const double original_number);
  ~RootCalculator() = default;

private:
  double createRandomValue() override;

  const double m_original_number;
  std::uniform_real_distribution<double> random_number;
};

class IntegrationCalculator : public MonteCarlo<double>
{
private:
  using RandomNumbers = std::vector<std::uniform_real_distribution<double>>;
public:
  using FunctionHandler = std::function<double(std::vector<double>)>;
  using RandomNumberRanges = std::vector<std::pair<double, double>>;

  IntegrationCalculator(FunctionHandler handler, RandomNumberRanges randomNumbers);
  ~IntegrationCalculator() = default;

private:
  double createRandomValue() override;

  FunctionHandler m_function;
  RandomNumbers m_randomNumbers;
  double m_rangeFactor;
};
