#ifndef STRATTWO_H_
#define STRATTWO_H_

#include <vector>
#include <thread>

class StratTwo {
    public:
        int cash=100000;
        int equity = 0;
        int avg_position_price = 0;
        int position_size = 0; // -1 to 1 representing fully short / fully long
        std::vector<int> data;


        StratTwo();

        // constructor
        StratTwo(std::vector<int> data);

        // strategy
        // returns -1 to 1 depending on what % of portfolio to sell / buy
        int Strategy(int datapoint);

        void runStrategy();

        int getEquity();

        void voidFunction();

        //std::thread voidFunctionThread();
};

#endif