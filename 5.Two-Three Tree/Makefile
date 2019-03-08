lab5: main.o Executive.o
	g++ -g -std=c++11 main.o Executive.o -o lab5

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp Node.h Node.hpp TwoThreeTree.h TwoThreeTree.hpp
	g++ -g -std=c++11 -c Executive.cpp

clean:
	rm *.o lab5
