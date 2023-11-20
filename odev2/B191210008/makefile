hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.cpp
	g++ -I ./include/ -o ./lib/AVL.o -c ./src/AVL.cpp
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/NodeStack.o -c ./src/NodeStack.cpp
	g++ -I ./include/ -o ./lib/NodeAVL.o -c ./src/NodeAVL.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Kisi.o ./lib/Stack.o ./lib/NodeStack.o ./lib/AVL.o ./lib/NodeAVL.o ./src/Test.cpp
	
calistir:
	./bin/Test