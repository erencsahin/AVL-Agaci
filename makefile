all: derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/avlTree.cpp -o ./lib/avlTree.o
	g++ -c -I "./include" ./src/avlNode.cpp -o ./lib/avlNode.o
	g++ -c -I "./include" ./src/stack.cpp -o ./lib/stack.o
bagla:
	g++ ./lib/main.o ./lib/avlTree.o ./lib/avlNode.o ./lib/stack.o -o ./bin/program
calistir:
	./bin/program