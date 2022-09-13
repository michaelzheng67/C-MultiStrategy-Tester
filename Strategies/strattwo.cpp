#include "strattwo.h"

#include <vector>
#include <iostream>
#include <thread>


StratTwo::StratTwo() : data(0) {}

// constructor
StratTwo::StratTwo(std::vector<int> data) {
    data = data;
}

// strategy
// returns 0 to 1 depending on what % of portfolio to have in given equity
int StratTwo::Strategy(int datapoint) {
    
    if (datapoint > 100) {
        return 1;
    } else {
        return 0;
    }
    
}

// runs the strategy on the given data to the object
void StratTwo::runStrategy() {
    
    // run strategy on each datapoint
    for (int i=0; i < data.size(); i++) {
        int new_size = StratTwo::Strategy(data[i]);
        int difference = position_size - new_size;

        // update cash and equity values
        
        
    }

} 

// getter method for equity value
int StratTwo::getEquity() {
    return equity;
}

void StratTwo::voidFunction() {
    std::cout << "2 working" << std::endl;
}
