#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void print_safe(const std::string& msg, int id) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << msg << ": " << id << std::endl;
}

int main() {
    std::thread t1(print_safe, "Thread", 1);
    std::thread t2(print_safe, "Thread", 2);
    t1.join(); t2.join();
}
