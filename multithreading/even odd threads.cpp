#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
bool odd_turn = true;

void print_odd() {
    for (int i = 1; i < 10; i += 2) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return odd_turn; });
        cout << i << " ";
        odd_turn = false;
        cv.notify_all();
    }
}

void print_even() {
    for (int i = 2; i <= 10; i += 2) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !odd_turn; });
        cout << i << " ";
        odd_turn = true;
        cv.notify_all();
    }
}

int main() {
    thread t1(print_odd);
    thread t2(print_even);
    t1.join();
    t2.join();
    return 0;
}
