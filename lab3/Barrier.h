/*! \file Barrier.h
    \brief Implementation of a Barrier using Semaphores.

   Uses C++11 features such as mutex and condition variables to implement a Barrier class
   using Semaphores for synchronization.
*/

#include "Semaphore.h"
#include <iostream>
#ifndef BARRIER_H
#define BARRIER_H

/*! \class Barrier
    \brief A Barrier Implementation

   Uses C++11 features such as mutex and condition variables to implement a Barrier class using Semaphores

*/
class Barrier
{
private:
  int taskCount; /*!< Total number of tasks to be performed. */
  int threadNum; /*!< Number of threads that have arrived at the barrier. */
  std::shared_ptr<Semaphore> mutexSem; /*!< Semaphore for mutual exclusion. */
  std::shared_ptr<Semaphore> barrierSem1; /*!< Semaphore for the first turnstile. */
  std::shared_ptr<Semaphore> barrierSem2; /*!< Semaphore for the second turnstile. */


public:
/*! \brief Default constructor for the Barrier class.

     Initializes the task count, thread number, and the required Semaphores.
  */
  Barrier();
  ~Barrier();
  Barrier(int count);
  int getCount();
  void waitForAll();
};
#endif // BARRIER_H
