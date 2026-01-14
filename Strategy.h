#pragma once

class Strategy {
public:
    virtual void onPrice(double price, int day) = 0;
    virtual bool shouldBuy() const = 0;
    virtual bool shouldSell() const = 0;
    virtual ~Strategy() = default;
};
