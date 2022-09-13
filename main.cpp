// Main file

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <thread>


// importing sample different strategies to test all at once
#include "Strategies/stratone.h"
#include "Strategies/strattwo.h"
#include "Strategies/stratthree.h"

// .h file from third party on Github to facilitate reading from csv file to vector data struct
// https://github.com/ben-strasser/fast-cpp-csv-parser
#include "csv.h"

// call on historical data and use it to backtest given strategy
// utilizes multithreading in order to test multiple stratgies at once 
// on read-only data

// strategies must have one main function which facilitates reading input and 
// creating trading strategies on.


// g++ -g -lpthread -std=c++17 main.cpp Strategies/stratone.cpp Strategies/strattwo.cpp Strategies/stratthree.cpp -o main
int main() {

    // extract SPY data
    io::CSVReader<7> in("SPY.csv");
    in.read_header(io::ignore_extra_column, "Date", "Open", "High", "Low", "Close", "Adj Close", "Volume");
    
    std::vector<float> open_vector;
    std::vector<float> high_vector;
    std::vector<float> low_vector;
    std::vector<float> close_vector;
    std::vector<float> adj_close_vector;
    std::vector<float> volume_vector;

    std::string date; float open; float high; float low; float close; float adj_close; float volume;

    while (in.read_row(date, open, high, low, close, adj_close, volume)) {
        open_vector.push_back(open);
        high_vector.push_back(high);
        low_vector.push_back(low);
        close_vector.push_back(close);
        adj_close_vector.push_back(adj_close);
        volume_vector.push_back(volume);
    }


    StratOne stratone_obj(close_vector);
    StratTwo strattwo_obj;
    StratThree stratthree_obj;
    

    // Can scale this to more than the three threads currently
    std::thread stratone_thread(std::bind(&StratOne::runStrategy, std::ref(stratone_obj)));
    std::thread strattwo_thread(std::bind(&StratTwo::voidFunction, std::ref(strattwo_obj)));
    std::thread stratthree_thread(std::bind(&StratThree::voidFunction, std::ref(stratthree_obj)));

    
    stratone_thread.join();
    strattwo_thread.join();
    stratthree_thread.join();

    // display results of running simulation
    std::cout << "Final value of strategy one is " << std::to_string(stratone_obj.getEquity() + stratone_obj.getCash()) << std::endl;

    return 0;
}