#ifndef STRATONE_H_
#define STRATONE_H_

#include <vector>
#include <thread>

class StratOne {
    public:
        int cash=100000; // starting off at t = 0 with all cash
        int equity = 0;
        int avg_position_price = 0;
        int position_size = 0; // -1 to 1 representing fully short / fully long
        std::vector<float> data;


        StratOne();

        // constructor
        StratOne(std::vector<float> data);

        // strategy
        // returns -1 to 1 depending on what % of portfolio to sell / buy
        int Strategy(int datapoint);

        void runStrategy();

        int getEquity();

        int getCash();

        void voidFunction();

        //std::thread voidFunctionThread();
};

#endif