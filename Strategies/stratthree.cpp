#include "stratthree.h"

#include <vector>
#include <iostream>
#include <thread>


StratThree::StratThree() : data(0) {}

// constructor
StratThree::StratThree(std::vector<float> close) {
    data = close;
    if (close.size() >= 4) {
        four_day_MA_vector.push_back(close[0]);
        four_day_MA_vector.push_back(close[1]);
        four_day_MA_vector.push_back(close[2]);
        four_day_MA_vector.push_back(close[3]);

        four_day_MA = (close[0] + close[1] + close[2] + close[3]) / 4;
    }
}

// strategy
// returns 0 to 1 depending on what % of portfolio to have in given equity
void StratThree::Strategy(int datapoint) {
    
    if (datapoint > four_day_MA) {
        StratThree::buyShares(10, datapoint);
    } else {
       StratThree::sellShares(10, datapoint);
    }
    
}

void StratThree::buyShares(int size, int price) {
    if (size * price <= cash) {
        position_size += size;
        cash -= size * price;
    }
}

void StratThree::sellShares(int size, int price) {
    if (size <= position_size) {
        position_size -= size;
        cash += size * price;
    }
}

// runs the strategy on the given data to the object
void StratThree::runStrategy() {
    
    // run strategy on each datapoint
    for (int i=0; i < data.size(); i++) {
        
        // edit 4MA vector based on new data and recalculate 4MA
        assert(!four_day_MA_vector.empty());
        four_day_MA_vector.erase(four_day_MA_vector.begin());
        four_day_MA_vector.push_back(data[i]);

        four_day_MA = 0;
        for (int i=0; i < four_day_MA_vector.size(); i++) {
            four_day_MA += four_day_MA_vector[i];
        }
        four_day_MA = four_day_MA / 4;

        StratThree::Strategy(data[i]);
        
        
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
