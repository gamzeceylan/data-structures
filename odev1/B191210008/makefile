CXXFLAGS=	-I "./include"

basla: program1
	./bin/program1.exe
program1: Node.o DoubleLinkedList.o Number.o Test.o
	g++ ./lib/Node.o ./lib/DoubleLinkedList.o ./lib/Number.o ./lib/Test.o -o ./bin/program1
	
Node.o:
	g++ $(CXXFLAGS) -c ./src/Node.cpp -o ./lib/Node.o 
DoubleLinkedList.o:
	g++ $(CXXFLAGS) -c ./src/DoubleLinkedList.cpp -o ./lib/DoubleLinkedList.o 
Number.o:
	g++ $(CXXFLAGS) -c ./src/Number.cpp -o ./lib/Number.o 
Test.o:
	g++ $(CXXFLAGS) -c ./src/Test.cpp -o ./lib/Test.o 