CC = gcc
CFLAGS = -Wall -std=c99

# Target files
TARGETS = signal_receiver signal_sender

all: $(TARGETS)

signal_receiver: signal_receiver.c
	$(CC) $(CFLAGS) -o signal_receiver signal_receiver.c

signal_sender: signal_sender.c
	$(CC) $(CFLAGS) -o signal_sender signal_sender.c

# run the -receiver
run_receiver: signal_receiver
	./signal_receiver

#  run the-sender
run_sender: signal_sender
	./signal_sender

clean:
	rm -f $(TARGETS)
