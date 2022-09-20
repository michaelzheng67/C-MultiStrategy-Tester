#ifndef STRATTWO_H_
#define STRATTWO_H_

#include <vector>
#include <thread>

class StratTwo {
    public:
        int cash=100000;
        int equity = 0;
        int position_size = 0; 
        std::vector<float> data;


        StratTwo();

        // constructor
        StratTwo(std::vector<float> data);

        // strategy
        void Strategy(int datapoint);

        void buyShares(int size, int price);

        void sellShares(int size, int price);

        void runStrategy();

        int getEquity();

        int getCash();
        
        void voidFunction();

        //std::thread voidFunctionThread();
};

#endif