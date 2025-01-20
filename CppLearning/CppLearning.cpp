/*
*  thread, mutex
*/

#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void IncrementCounter(const std::string& threadName) {
    for (int i = 0; i < 5; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++counter;
        std::cout << threadName << " incremented counter to " << counter << std::endl;
    }
}

int main() {
    std::thread t1(IncrementCounter, "Thread 1");
    std::thread t2(IncrementCounter, "Thread 2");

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << std::endl;
    return 0;
}