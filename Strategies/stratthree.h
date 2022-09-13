#ifndef STRATTHREE_H_
#define STRATTHREE_H_

#include <vector>
#include <thread>

class StratThree {
    public:
        int cash=100000;
        int equity = 0;
        int avg_position_price = 0;
        int position_size = 0; // -1 to 1 representing fully short / fully long
        std::vector<int> data;


        StratThree();

        // constructor
        StratThree(std::vector<int> data);

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