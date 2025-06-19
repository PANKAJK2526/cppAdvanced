#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

std::queue<int> buffer;
const int max_size = 5;
std::mutex mtx;
std::condition_variable cv;

void producer() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return buffer.size() < max_size; });
        buffer.push(i);
        std::cout << "Produced: " << i << std::endl;
        cv.notify_all();
    }
}

void consumer() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !buffer.empty(); });
        int val = buffer.front(); buffer.pop();
        std::cout << "Consumed: " << val << std::endl;
        cv.notify_all();
    }
}

int main() {
    std::thread t1(producer), t2(consumer);
    t1.join(); t2.join();
}
