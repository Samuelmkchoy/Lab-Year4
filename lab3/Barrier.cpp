/*! \file Barrier.h
    \brief Implementation of a barrier using Semaphores.

   Uses C++11 features such as mutex and condition variables to implement a barrier
   using Semaphores with N number of threads.
*/
#include "Barrier.h"

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads

*/


/*!
 * \brief Constructor for the Barrier class.
 *
 * Initializes the task count, thread number, and the required Semaphores.
 */Barrier::Barrier(){

  taskCount = 0;
  threadNum = 0;
  mutexSem=std::make_shared<Semaphore>(1);
  barrierSem1 = std::make_shared<Semaphore>(0);
  barrierSem2 = std::make_shared<Semaphore>(1);

}
/*!
 * \brief Constructor for the Barrier class with a parameter.
 *
 * Initializes the task count with the provided value and initializes
 * the thread number and the required Semaphores.
 *
 * \param taskCount The total number of tasks to be performed.
 */
Barrier::Barrier(int taskCount){

  this->taskCount = taskCount;
  threadNum = 0;
  mutexSem = std::make_shared<Semaphore>(1);
  barrierSem1 = std::make_shared<Semaphore>(0);
  barrierSem2 = std::make_shared<Semaphore>(1); // Add the second turnstile semaphore
}
/*! Barrier deconstructor*/
Barrier::~Barrier(){

}

/*!
 * \brief Gets the current count value.
 *
 * \return The current count value.
 */
int Barrier::getCount(){

  return this->taskCount;
}

/*!
 * \brief Waits for all threads to reach the barrier before proceeding.
 *
 * This function uses Semaphores and mutex to synchronize threads at the barrier.
 * After all threads arrive, it releases them to proceed with the second half of the code.
 */
void Barrier::waitForAll(){

  mutexSem->Wait();
  threadNum++;

  if(threadNum == taskCount){
    barrierSem2->Wait();
    barrierSem1->Signal();
  }
  mutexSem->Signal();
  barrierSem1->Wait();
  barrierSem1->Signal();

  mutexSem->Wait();
  threadNum--;

  if(threadNum == 0){
    barrierSem1->Wait();
    barrierSem2->Signal();
    threadNum = 0;
  }
  mutexSem->Signal();
  barrierSem2->Wait();
  barrierSem2->Signal();
}
