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
int StratOne::Strategy(int datapoint) {
    
    if (datapoint > 100) {
        return 1;
    } else {
        return 0;
    }
    
}

// runs the strategy on the given data to the object
void StratOne::runStrategy() {
    
    // run strategy on each datapoint
    for (int i=0; i < data.size(); i++) {
        //int new_size = StratOne::Strategy(data[i]);
        //int difference = position_size - new_size;
        // update cash and equity values
         
        
    }

} 

// getter methods
int StratOne::getEquity() {
    return equity;
}

int StratOne::getCash() {
    return cash;
}

void StratOne::voidFunction() {
    std::cout << "1 working" << std::endl;
}


