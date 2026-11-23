*This project has been created as part of the 42 curriculum by `<glicciar>`.*

# philosophers

> The dining philosophers problem, solved with threads and mutexes.

## Description

Several philosophers sit around a table. Each one alternates between eating, sleeping and thinking, and needs two forks to eat. The project is about concurrent programming: avoiding data races and deadlocks while no philosopher starves.

**Rules**
- Each philosopher is a separate thread
- There is one fork between each pair of philosophers, and each fork's state is protected by a mutex
- The simulation ends when a philosopher dies, or when each one has eaten the required number of times
- State changes are printed with a timestamp, and must not be mixed up

Bonus (processes and semaphores): not implemented.

## Instructions

**Requirements:** `cc`, `make`, POSIX threads.

```bash
cd philo
make
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
All times are in milliseconds.

**Example**
```bash
./philo 5 800 200 200
```

## Resources
- `man pthread_create`, `man pthread_mutex_lock`
- Articles on the dining philosophers problem

**Use of AI**
- Code assistence and debugging
