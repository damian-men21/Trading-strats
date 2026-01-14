#include"CSVLoader.h"
#include "Backtester.h"
#include "MovingAverageStrategy.h"

int main() {

auto prices = CSVLoader::loadPrices("data/sample_prices.csv");
MovingAverageStrategy strat(20, 50);
Backtester bt(10000);
double finalValue = bt.run(prices, strat);
bt.printReport();
}
