#ifndef STRATTHREE_H_
#define STRATTHREE_H_

#include <vector>
#include <thread>

class StratThree {
    public:
        int cash=100000;
        int equity = 0;
        int position_size = 0; // -1 to 1 representing fully short / fully long
        int four_day_MA;
        std::vector<float> four_day_MA_vector;
        std::vector<float> data;
        



        StratThree();

        // constructor
        StratThree(std::vector<float> data);

        // strategy
        // returns -1 to 1 depending on what % of portfolio to sell / buy
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