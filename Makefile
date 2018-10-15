all : chain

#test: main.o blockChain.o blockChain.h
#	g++ -g -o test main.o blockChain.o
#main.o: main.cpp
#	g++ -c -g main.cpp
#blockChain.o: blockChain.cpp
#	g++ -c -g blockChain.cpp
chain:
	g++ main.cpp blockChain.cpp -o chain -I $HOME/include -L $HOME/lib -lcrypto
clean:
	#rm *.o
	rm chain
