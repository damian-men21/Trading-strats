#include "Backtester.h"
#include <iostream> 

Backtester::Backtester(double startingCapital) : capital(startingCapital) {}

double Backtester::run(const std::vector<double>& prices, Strategy& strategy) {
  
  for (int i = 0; i < prices.size(); i++) {
    double price = prices[i]; strategy.onPrice(price, i);
    if (!trade.open && strategy.shouldBuy()) {
      trade.entryPrice = price; trade.open = true;
    }
    else if (trade.open && strategy.shouldSell()) { 
      trade.exitPrice = price;
      capital *= (trade.exitPrice / trade.entryPrice);
      trade.open = false; tradesExecuted++;
    }
  }
  return capital;
}
void Backtester::printReport() const {
  std::cout << "Trades executed: " << tradesExecuted << "\n";
  std::cout << "Final Portfolio Value: $" << capital << "\n"; 
}
