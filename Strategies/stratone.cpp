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

// walk forward optimization function. Outputs the optimal weight to go long at based on historical data (returns 0 - 1)
int StratOne::walkForwardOptimization(int min, int max) {
    // assuming the data has >= 253 data points 
    // 10 windows to test on
    std::vector<float> window_1;
    std::vector<float> window_2;
    std::vector<float> window_3;
    std::vector<float> window_4;
    std::vector<float> window_5;
    std::vector<float> window_6;
    std::vector<float> window_7;
    std::vector<float> window_8;
    std::vector<float> window_9;
    std::vector<float> window_10;

    for (int i=0; i < 25; i++) {
        window_1.push_back(data[i])
    }

    for (int i=25; i < 50; i++) {
        window_2.push_back(data[i])
    }

    for (int i=50; i < 75; i++) {
        window_3.push_back(data[i])
    }

    for (int i=75; i < 100; i++) {
        window_4.push_back(data[i])
    }

    for (int i=100; i < 125; i++) {
        window_5.push_back(data[i])
    }

    for (int i=125; i < 150; i++) {
        window_6.push_back(data[i])
    }

    for (int i=150; i < 175; i++) {
        window_7.push_back(data[i])
    }

    for (int i=175; i < 200; i++) {
        window_8.push_back(data[i])
    }

    for (int i=200; i < 225; i++) {
        window_9.push_back(data[i])
    }

    for (int i=225; i < 250; i++) {
        window_10.push_back(data[i])
    }

    std::vector<std::vector<float>> windows_array;
    windows_array.push_back(window_1);
    windows_array.push_back(window_2);
    windows_array.push_back(window_3);
    windows_array.push_back(window_4);
    windows_array.push_back(window_5);
    windows_array.push_back(window_6);
    windows_array.push_back(window_7);
    windows_array.push_back(window_8);
    windows_array.push_back(window_9);
    windows_array.push_back(window_10);


    std::vector<float> optimal_weights;
    for (int i=0; i < windows_array.size(); i++) {
        float optimal_weight = min;
        
        for (float i=min; i < max; i += 0.1) {
            
        }

        optimal_weights.push_back(optimal_weight);
    }

    // 15 are used to tune the variables
    


    // 10 used to test 
    

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


