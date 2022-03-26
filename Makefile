CC=gcc
TARGET=What2Eat

all: What2Eat.o
	$(CC) -o $(TARGET) What2Eat.o
clean:
	rm -f *.o $(TARGET)
