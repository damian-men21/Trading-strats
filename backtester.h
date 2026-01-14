#pragma once
#include "Strategy.h"
#include "Trade.h"
#include <vector>

class Backtester {

public: 
Backtester(double startingCapital);
double run(const std::vector<double>& prices, Strategy& strategy);
void printReport() const;

private: 
double capital;
Trade trade; int tradesExecuted = 0; 
};
