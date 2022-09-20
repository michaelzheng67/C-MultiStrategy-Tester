#ifndef STRATONE_H_
#define STRATONE_H_

#include <vector>
#include <thread>


// long only strategy
class StratOne {
    public:
        int cash=100000; // starting off at t = 0 with all cash
        int equity = 0;
        int position_size = 0; 
        std::vector<float> data;


        StratOne();

        // constructor
        StratOne(std::vector<float> data);

        // strategy
        // returns -1 to 1 depending on what % of portfolio to sell / buy
        void Strategy(int datapoint);

        void buyShares(int size, int price);

        void sellShares(int size, int price);

        void runStrategy();

        int getEquity();

        int getCash();

        int getFinalValue();

        //std::thread voidFunctionThread();
};

#endif