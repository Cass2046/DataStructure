lab10: main.o Executive.o
	g++ -g -std=c++11 main.o Executive.o -o lab10

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -c main.cpp

Executive.o: Executive.h Executive.cpp SkewNode.h SkewNode.hpp MinSkewHeap.h MinSkewHeap.hpp LeftistNode.h LeftistNode.hpp MinLeftistHeap.h MinLeftistHeap.hpp Queue.h Queue.hpp
	g++ -g -std=c++11 -c Executive.cpp

clean:
	rm *.o lab10
