#Use the g++ compiler                                                                                                                                                                                                                         
CC = g++

# Compiler flags:                                                                                                                                                                                                                             
#   -Wall (most warnings enabled)                                                                                                                                                                                                             
#   -g (for debugging with gdb)                                                                                                                                                                                                               
CFLAGS = -Wall

# Executable name:                                                                                                                                                                                                                            	
TARGET = steganography

all: main.o  steganography.o  steganography

$(TARGET): main.o steganography.o
	 $(CC) $(CFLAGS) main.o steganography.o  -o $(TARGET)

main.o: main.cpp steganography.o	
	$(CC) $(CFLAGS) main.cpp -c

steganography.o: steganography.cpp steganography.h
	$(CC)  $(CFLAGS) steganography.cpp -c

clean:
	rm *.o *~ $(TARGET)







