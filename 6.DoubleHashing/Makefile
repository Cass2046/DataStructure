lab6: main.o Executive.o
	g++ -g -std=c++11 main.o Executive.o -o lab6

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp Node.h Node.hpp List.h List.hpp Bucket.h Bucket.hpp Quadratic.h Quadratic.hpp DoubleH.h DoubleH.hpp Timer.cpp
	g++ -g -std=c++11 -c Executive.cpp

clean:
	rm *.o lab6
