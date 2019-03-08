lab1: main.o Executive.o
	g++ -g -std=c++11 main.o Executive.o -o lab3

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp Bucket.h Bucket.hpp Quadratic.h Quadratic.hpp DoubleH.h DoubleH.hpp
	g++ -g -std=c++11 -c Executive.cpp

clean:
	rm *.o lab3
