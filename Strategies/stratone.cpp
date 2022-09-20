#include "stratone.h"

#include <vector>
#include <iostream>
#include <thread>


StratOne::StratOne() : data(0) {}

// constructor
StratOne::StratOne(std::vector<float> close) {
    data = close;
}

// strategy
// returns 0 to 1 depending on what % of portfolio to have in given equity
void StratOne::Strategy(int datapoint) {
    
    if (datapoint > 100) {
        StratOne::buyShares(10, datapoint);
    } else {
        StratOne::sellShares(10, datapoint);
    }
    
}


// helper methods for strategy method

void StratOne::buyShares(int size, int price) {
    if (size * price <= cash) {
        position_size += size;
        cash -= size * price;
    }
}

void StratOne::sellShares(int size, int price) {
    if (size <= position_size) {
        position_size -= size;
        cash += size * price;
    }
}

// runs the strategy on the given data to the object
void StratOne::runStrategy() {
    
    // run strategy on each datapoint
    for (int i=0; i < data.size(); i++) {
        equity = position_size * data[i];
        StratOne::Strategy(data[i]);
    }


   

} 

// getter methods
int StratOne::getEquity() {
    return equity;
}

int StratOne::getCash() {
    return cash;
}

int StratOne::getFinalValue() {
    return equity + cash;
}


