#include "stratthree.h"

#include <vector>
#include <iostream>
#include <thread>


StratThree::StratThree() : data(0) {}

// constructor
StratThree::StratThree(std::vector<int> data) {
    data = data;
}

// strategy
// returns 0 to 1 depending on what % of portfolio to have in given equity
int StratThree::Strategy(int datapoint) {
    
    if (datapoint > 100) {
        return 1;
    } else {
        return 0;
    }
    
}

// runs the strategy on the given data to the object
void StratThree::runStrategy() {
    
    // run strategy on each datapoint
    for (int i=0; i < data.size(); i++) {
        int new_size = StratThree::Strategy(data[i]);
        int difference = position_size - new_size;

        // update cash and equity values
        
        
    }

} 

// getter methods
int StratThree::getEquity() {
    return equity;
}

int StratThree::getCash() {
    return cash;
}



void StratThree::voidFunction() {
    std::cout << "3 working" << std::endl;
}
