lab9: main.o Executive.o
	g++ -g -std=c++11 main.o Executive.o -o lab9

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp BinaryNode.h BinaryNode.hpp BST.h BST.hpp Max_Five_Heap.h Max_Five_Heap.hpp Min_Five_Heap.h Min_Five_Heap.hpp Timer.cpp
	g++ -g -std=c++11 -c Executive.cpp

clean:
	rm *.o lab9
