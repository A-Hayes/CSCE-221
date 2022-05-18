all: Main

Main: DoublyLinkedList.o MinQueue.o Main.o
	g++ -std=c++11 DoublyLinkedList.o MinQueue.o Main.o -o Main

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -std=c++11 -c DoublyLinkedList.cpp

MinQueue.o: MinQueue.cpp MinQueue.h
	g++ -std=c++11 -c MinQueue.cpp

Main.o: Main.cpp MinQueue.h
	g++ -std=c++11 -c Main.cpp

clean:
	rm *.o Main
