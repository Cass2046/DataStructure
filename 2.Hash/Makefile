lab1: main.o Executive.o
	g++ -g -std=c++11 main.o Executive.o -o lab2

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp Hashing.h Hashing.hpp List.h List.hpp Node.h Node.hpp 
	g++ -g -std=c++11 -c Executive.cpp

clean:
	rm *.o lab2
