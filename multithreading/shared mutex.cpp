#include <iostream>
#include <thread>
#include <shared_mutex>

int data = 0;
std::shared_mutex rw_lock;

void reader(int id) {
    std::shared_lock lock(rw_lock);
    std::cout << "Reader " << id << " reads data: " << data << std::endl;
}

void writer(int id) {
    std::unique_lock lock(rw_lock);
    data += 1;
    std::cout << "Writer " << id << " updates data to: " << data << std::endl;
}

int main() {
    std::thread t1(reader, 1);
    std::thread t2(writer, 1);
    std::thread t3(reader, 2);
    t1.join(); t2.join(); t3.join();
}
