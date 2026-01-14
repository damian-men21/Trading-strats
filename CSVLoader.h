#pragma once
#include <vector>
#include <string>

class CSVLoader {
public:
static std::vector<double> loadPrices(const std::string& path);
};
