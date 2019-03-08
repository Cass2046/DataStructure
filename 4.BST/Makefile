lab4: main.o Executive.o
	g++ -g -std=c++11 main.o Executive.o -o lab4

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp BinaryNode.h BinaryNode.hpp BST.h BST.hpp
	g++ -g -std=c++11 -c Executive.cpp

clean:
	rm *.o lab4
