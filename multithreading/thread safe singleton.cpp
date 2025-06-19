#include <iostream>
#include <fstream>
#include <mutex>
#include <thread>

class Logger {
    std::mutex m;
    std::ofstream file;

    Logger() { file.open("log.txt"); }
public:
    static Logger& instance() {
        static Logger instance;
        return instance;
    }

    void log(const std::string& msg) {
        std::lock_guard<std::mutex> lock(m);
        file << msg << std::endl;
    }

    ~Logger() { file.close(); }
};

void worker(int id) {
    for (int i = 0; i < 3; ++i) {
        Logger::instance().log("Thread " + std::to_string(id) + " log " + std::to_string(i));
    }
}

int main() {
    std::thread t1(worker, 1), t2(worker, 2);
    t1.join(); t2.join();
}
