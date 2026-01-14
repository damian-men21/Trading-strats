#pragma once 
#include "Strategy.h"
#include <vector>

class MovingAverageStrategy : public Strategy {

public:
MovingAverageStrategy(int shortWindow, int longWindow);

void onPrice(double price, int day) override;
bool shouldBuy() const override;
bool shouldSell() const override;

private:
int shortW, longW;
std::vector<double> prices;
double sma(int window) const;
};
