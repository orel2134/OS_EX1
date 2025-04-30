CC = gcc
CFLAGS = -Wall -std=c99

# קובצי היעד
TARGETS = signal_receiver signal_sender

all: $(TARGETS)

signal_receiver: signal_receiver.c
	$(CC) $(CFLAGS) -o signal_receiver signal_receiver.c

signal_sender: signal_sender.c
	$(CC) $(CFLAGS) -o signal_sender signal_sender.c

# הרצת ה-receiver
run_receiver: signal_receiver
	./signal_receiver

# הרצת ה-sender
run_sender: signal_sender
	./signal_sender

clean:
	rm -f $(TARGETS)
