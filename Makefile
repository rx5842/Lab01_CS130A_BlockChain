all : test

test: main.o blockChain.o blockChain.h
	g++ -g -o test main.o blockChain.o
main.o: main.cpp
	g++ -c -g main.cpp
blockChain.o: blockChain.cpp
	g++ -c -g blockChain.cpp
clean:
	rm *.o
	rm test
