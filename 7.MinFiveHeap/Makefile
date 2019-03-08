lab7: main.o Executive.o
	g++ -g -std=c++11 main.o Executive.o -o lab7

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp Min_Five_Heap.h Min_Five_Heap.hpp Max_Five_Heap.h Max_Five_Heap.hpp
	g++ -g -std=c++11 -c Executive.cpp

clean:
	rm *.o lab7
