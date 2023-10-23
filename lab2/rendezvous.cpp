#include "Semaphore.h"
#include <thread>
#include <vector>
#include <iostream>

void task(std::shared_ptr<Semaphore> mutexSem, std::shared_ptr<Semaphore> barrierSem, int threadCount) {
    for (int i = 0; i < threadCount; i++) {
        // Wait until all threads have reached this point
        barrierSem->Wait();
        
        // Print "first" only when it's the first thread
        if (i == 0) {
            std::cout << "first" << std::endl;
        }
        
        // Release the mutex so the next thread can print "first"
        mutexSem->Signal();
        
        // Wait for the mutex to be released
        mutexSem->Wait();
        
        // Print "second"
        std::cout << "second" << std::endl;
        
        // Release the barrier for the next iteration
        barrierSem->Signal();
    }
}

int main(void) {
    std::shared_ptr<Semaphore> mutexSem;
    std::shared_ptr<Semaphore> barrierSem;
    int threadCount = 5;
    mutexSem = std::make_shared<Semaphore>(1);
    barrierSem = std::make_shared<Semaphore>(0);

    std::vector<std::thread> threadArray(threadCount);

    for (int i = 0; i < threadArray.size(); i++) {
        threadArray[i] = std::thread(task, mutexSem, barrierSem, threadCount);
    }

    // Release the first barrier to start the threads
    barrierSem->Signal();

    for (int i = 0; i < threadArray.size(); i++) {
        threadArray[i].join();
    }

    return 0;
}
