#include "CSVLoader.h"
#include <fstream>
#include <sstream>

std::vector<double> CSVLoader::loadPrices(const std::string& path) {
  std::vector<double> prices;
  std::ifstream file(path);
  std::string line;
  
  while (std::getline(file, line)) {
    if (line.empty()) continue;
    prices.push_back(std::stod(line));
  }
  return prices;
}
