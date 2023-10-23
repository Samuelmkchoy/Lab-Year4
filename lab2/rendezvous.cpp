#include "Semaphore.h"
#include <thread>
#include <vector>
#include <iostream>

void task(std::shared_ptr<int> numberArrived, std::shared_ptr<Semaphore> mutexSem,std::shared_ptr<Semaphore> barrierSem, int threadCount){
    
    std::cout << "first" << std::endl;

    // Wait for the mutex to be released
    mutexSem->Wait();
    *numberArrived = *numberArrived+1;
    //*numberArrived++; // i keep getting error by here

    if(*numberArrived==threadCount){ 
        // Release the barrier for the next iteration
        barrierSem->Signal();
    }
    // Release the mutex
    mutexSem->Signal();
    //Wait for signal from last thread and immediately signal the next thread 
    barrierSem->Wait();
    barrierSem->Signal();
    
    // Print "second"
    std::cout << "second" << std::endl;
}

int main(void){
  std::shared_ptr<int> numberArrived;
  std::shared_ptr<Semaphore> mutexSem;
  std::shared_ptr<Semaphore> barrierSem;
  int threadCount = 5;
  numberArrived=std::make_shared<int>(0);
  mutexSem=std::make_shared<Semaphore>(1);
  barrierSem=std::make_shared<Semaphore>(0);
  /*!< An array of threads*/
  std::vector<std::thread> threadArray(threadCount);
  /*!< Pointer to barrier object*/

  for(int i=0; i < threadArray.size(); i++){
    threadArray[i]=std::thread(task,numberArrived,mutexSem,barrierSem,threadCount);
  }

  for(int i = 0; i < threadArray.size(); i++){
    threadArray[i].join();
  }
  
  return 0;
}
