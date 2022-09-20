#include "strattwo.h"

#include <vector>
#include <iostream>
#include <thread>


StratTwo::StratTwo() : data(0) {}

// constructor
StratTwo::StratTwo(std::vector<float> close) {
    data = close;
}

// strategy
// returns 0 to 1 depending on what % of portfolio to have in given equity
void StratTwo::Strategy(int datapoint) {
    if (datapoint > 100) {
        StratTwo::sellShares(10, datapoint);
    } else {
        StratTwo::buyShares(10, datapoint);
    }
    
}

// helper functions
void StratTwo::buyShares(int size, int price) {
    if (size * price <= cash) {
        position_size += size;
        cash -= size * price;
    }
}

void StratTwo::sellShares(int size, int price) {
    position_size -= size;
    cash += size * price;
    
}


// runs the strategy on the given data to the object
void StratTwo::runStrategy() {
    
    // run strategy on each datapoint
    for (int i=0; i < data.size(); i++) {
        equity = position_size * data[i];
        StratTwo::Strategy(data[i]);
        
    }

} 

// getter methods
int StratTwo::getEquity() {
    return equity;
}

int StratTwo::getCash() {
    return cash;
}

void StratTwo::voidFunction() {
    std::cout << "2 working" << std::endl;
}
