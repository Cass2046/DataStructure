lab8: main.o Executive.o
	g++ -g -std=c++11 main.o Executive.o -o lab08

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp MinMaxHeap.h MinMaxHeap.hpp MaxMinHeap.h MaxMinHeap.hpp
	g++ -g -std=c++11 -c Executive.cpp

clean:
	rm *.o lab08
