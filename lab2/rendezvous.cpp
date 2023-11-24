/*! \class rendezvous

 * \brief The task function executed by each thread.
 *
 * This function demonstrates a simple barrier synchronization using Semaphores.
 * Each thread prints "first", increments a shared counter, waits for all threads
 * to arrive at the barrier, prints "second", and repeats the process.
 *
 * \param numberArrived A shared pointer to a counter tracking the number of threads that arrived.
 * \param mutexSem A shared pointer to a Semaphore for mutual exclusion.
 * \param barrierSem A shared pointer to a Semaphore for barrier synchronization.
 * \param threadCount The total number of threads participating in the barrier.
 */

#ifndef RENDEZVOUS.CPP
#define RENDEZVOUS.CPP 
#include "Semaphore.h"
#include <thread>
#include <vector>
#include <iostream>

/*!
 * \brief The task function executed by each thread.
 *
 * This function demonstrates a simple barrier synchronization using Semaphores.
 * Each thread prints "first", increments a shared counter, waits for all threads
 * to arrive at the barrier, prints "second", and repeats the process.
 *
 * \param numberArrived A shared pointer to a counter tracking the number of threads that arrived.
 * \param mutexSem A shared pointer to a Semaphore for mutual exclusion.
 * \param barrierSem A shared pointer to a Semaphore for barrier synchronization.
 * \param threadCount The total number of threads participating in the barrier.
 */

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

/*!
 * \brief The main function where the program starts execution.
 *
 * This function initializes shared resources, creates a vector of threads,
 * launches the threads to execute the task function, and waits for all threads to finish.
 *
 * \return Returns 0 upon successful execution.
 */
 
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

#endif