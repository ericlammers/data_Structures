OBJ = main.o Heap.o Node.o BinarySearchTree.o

a2:	$(OBJ)
	g++ -o data_Structures $(OBJ)

main.o:	main.cc Heap.h Node.h
	g++ -c main.cc

Heap.o:	Heap.cc Heap.h 
	g++ -c Heap.cc

Node.o: Node.cc Node.h
	g++ -c Node.cc

BinarySearchTree.o: BinarySearchTree.cc BinarySearchTree.h Node.h
	g++ -c BinarySearchTree.cc

clean:
	rm -f *.o data_Structures
