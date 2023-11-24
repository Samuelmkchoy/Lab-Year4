#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>

/*!
 * \brief Displays a message first.
 *
 * This function sleeps for the specified duration and then prints a message.
 * After printing, it signals the provided semaphore to notify taskTwo to start.
 *
 * \param theSemaphore A shared pointer to the Semaphore object.
 * \param delay The delay (in seconds) before printing the message.
 */
 void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay){
  sleep(delay);
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  //tell taskTwo to start now
  theSemaphore->Signal();
}

/*!
 * \brief Displays a message second.
 *
 * This function waits for theSemaphore to be signaled by taskOne before printing
 * its message. It then prints a message with a delay of 5 seconds.
 *
 * \param theSemaphore A shared pointer to the Semaphore object.
 */

void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  //wait here until taskOne finishes...
  theSemaphore->Wait(); 
  std::cout <<"This ";
  std::cout << "will ";
  sleep(5);
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}

/*!
 * \brief The main function where the program starts execution.
 *
 * This function creates two threads, threadOne and threadTwo, and launches them.
 * It uses a Semaphore to coordinate the execution of taskOne and taskTwo.
 * The main function waits for both threads to finish before returning.
 *
 * \return Returns 0 upon successful execution.
 */
 
int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  sem->Signal();sem->Wait();//these serve no purpose
  /**< Launch the threads  */
  int taskOneDelay=5;
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem,taskOneDelay);
  std::cout << "Launched from the main\n";
   /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();
  return 0;
}
