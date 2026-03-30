# *This project has been created as part of the 42 curriculum by adrocha-.*

# Philosophers

##  Description

The **Philosophers** project is an introduction to multithreading and synchronization in C.  
It is based on the classic computer science problem known as the **Dining Philosophers Problem**.

The goal of this project is to simulate a group of philosophers sitting at a table, where each philosopher alternates between eating, thinking, and sleeping. To eat, a philosopher must pick up two forks (shared resources), which introduces challenges related to concurrency such as:

- Race conditions  
- Deadlocks  
- Data races  
- Thread synchronization  

The project aims to teach how to manage threads and protect shared resources using mutexes, ensuring that the simulation runs correctly without conflicts.

--------------------------------------------------------------------

## Instructions & Compilation

To compile the project, run:

bash --> make

This will generate the executable:

./philo

# Usage
./philo number_of_philosophers  time_to_die  time_to_eat time_to_sleep  [number_of_times_each_philosopher_must_eat]

# Arguments
number_of_philosophers: number of philosophers (and forks)

time_to_die: time (in ms) a philosopher can live without eating

time_to_eat: time (in ms) it takes for a philosopher to eat

time_to_sleep: time (in ms) a philosopher spends sleeping

[optional] number_of_times_each_philosopher_must_eat: simulation stops when all philosophers have eaten this many times

# Example
./philo 5 800 200 200

This runs a simulation with:

5 philosophers;
Each philosopher dies if they don't eat within 800ms;
Eating takes 200ms;
Sleeping takes 200ms.

-------------------------------------------------------------------

# Features 
Multithreading using pthread

Mutex-based fork protection

Death monitoring system

Precise time management

Prevention of data races

Clean memory management (no leaks)

# Technical Choices 
Each philosopher is represented by a thread

Forks are protected using mutexes

A monitoring mechanism checks if a philosopher dies

Time is handled using timestamps in milliseconds

Custom sleep function for better precision

# Resources 
* Documentation

- POSIX Threads (pthreads)

- Mutex and thread synchronization concepts

- Dining Philosophers Problem (classic concurrency problem)

# Useful Links
https://man7.org/linux/man-pages/man7/pthreads.7.html

https://en.wikipedia.org/wiki/Dining_philosophers_problem

https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3.html

# Notes
The program avoids deadlocks by carefully ordering fork acquisition

Output is synchronized to prevent mixed logs

The simulation stops immediately when a philosopher dies

## All code was written, tested, and validated by the author.