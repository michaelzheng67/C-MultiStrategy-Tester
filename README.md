# C++ MultiThreaded Strategy Tester

This project was meant to help me first and foremost get some experience with C++ and its 
thread library to allow for multithreading.

There are three arbitrary strategies being tested (each with a void function that runs their strategy
on the given SPY data). In the main file, each strategy is given its own thread to run on. This
setup can be scaled up to an arbitrary amount of threads (as hardware constraints allow).

Moreover, on Strategy 1 I am trying out creating a function that can run a walk forward optimization on the variable
of how much of the portfolio to go long on SPY. Can extrapolate this function to any strategy as long as it meets its constraints
