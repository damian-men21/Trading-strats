#include "MovingAverageStrategy.h"

MovingAverageStrategy::MovingAverageStrategy(int s, int l) : shortW(s), longW(l) {}

void MovingAverageStrategy::onPrice(double price, int) {
  prices.push_back(price);
}

double MovingAverageStrategy::sma(int window) const {
  if (prices.size() < window) return 0.0;
  double sum = 0;
  for (int i = prices.size() - window; i < prices.size(); i++)
    sum += prices[i];
  return sum / window;
}
bool MovingAverageStrategy::shouldBuy() const {
  return sma(shortW) > sma(longW);
}
bool MovingAverageStrategy::shouldSell() const {
  return sma(shortW) < sma(longW); 
}
