UNAME_S := $(shell uname -s)
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf

all: test rsdl.o

test: build/main.o build/rsdl.o
	g++ main.o rsdl.o $(CCFLAGS) -o test.out

main.o: src/rsdl/rsdl.hpp  src/main.cpp
	g++ -c example/main.cpp -o build/main.o

rsdl.o: src/rsdl/rsdl.hpp src/rsdl/rsdl.cpp
	g++ -c src/rsdl.cpp -o build/rsdl.o

.PHONY: clean
clean:
	rm -r *.o
