# Makefile
CC = gcc
CFLAGS = -pthread

# List of programs to be built
PROGS = adder subtractor multiplier divider worker_monitor

all: $(PROGS)

adder: src/adder.c
	$(CC) $(CFLAGS) -o adder src/adder.c

subtractor: src/subtractor.c
	$(CC) $(CFLAGS) -o subtractor src/subtractor.c

multiplier: src/multiplier.c
	$(CC) $(CFLAGS) -o multiplier src/multiplier.c

divider: src/divider.c
	$(CC) $(CFLAGS) -o divider src/divider.c

worker_monitor: src/worker_monitor.c
	$(CC) $(CFLAGS) -o worker_monitor src/worker_monitor.c

# Clean up the mess: -f means force, *~ means all files ending with ~ (oftenly backup files), *.o means all files ending with .o (object files created by the compiler)
clean:
	rm -f $(PROGS) *.o *~
