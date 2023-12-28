# OS Worker Monitoring

## Prerequisites

- Must be able to use a Linux-based operating system.
- Must be able to use the terminal.
- Basic knowledge of the C language.
- Ability to compile programs from the terminal.
- Ability to create processes.
- Ability to make program calls.
- Ability to communicate between processes.
- Ability to use threads.
- Ability to use signals.

## Project Name

**OS Worker Monitoring**

## Project Overview

There are five programs in the project:

- `adder.c` -> `adder`
- `subtractor.c` -> `subtractor`
- `multiplier.c` -> `multiplier`
- `divider.c` -> `divider`
- `worker_monitor.c` -> `wm`

Each program must run in a separate terminal. Worker programs constantly request two numbers from the keyboard and perform the corresponding operation on them. The worker monitor program shows every operation performed by the workers on its own screen.

## Project Details

- Each program runs in a separate terminal.
- Worker programs perform arithmetic operations based on user input.
- Worker monitor displays operations from all workers simultaneously.
- Worker monitor uses multiple threads and lock mechanisms to ensure proper synchronization.
- If a worker has started calculating, the operations of other workers are held until that worker finishes its job.

## Project Delivery

- Project written in C language.
- Consideration of operating system course topics.
- Properly formatted project report.
- Project code includes comment lines.
- Includes a Makefile for automatic compilation.
  
### Documents to be included in the project file:

- `makefile`
- `adder.c` -> `adder`
- `subtractor.c` -> `subtractor`
- `multiplier.c` -> `multiplier`
- `divider.c` -> `divider`
- `worker_monitor.c` -> `wm`