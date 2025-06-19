#include <iostream>
#include <thread>

thread_local int local_value = 0;

void task(int id) {
    for (int i = 0; i < 3; ++i) {
        ++local_value;
        std::cout << "Thread " << id << " local value: " << local_value << std::endl;
    }
}

int main() {
    std::thread t1(task, 1), t2(task, 2);
    t1.join(); t2.join();
}
