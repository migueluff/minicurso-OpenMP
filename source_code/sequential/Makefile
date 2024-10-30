CC = gcc

CFLAGS_SEQ =          
CFLAGS_PAR = -fopenmp 

all: compile

compile:
	$(CC) $(CFLAGS_SEQ) -o output $(SOURCE)

# Clean
clean:
	rm -f output
