OBJ = main.o Heap.o

a2:	$(OBJ)
	g++ -o data_Structures $(OBJ)

main.o:	main.cc
	g++ -c main.cc

Heap.o:	Heap.cc Heap.h 
	g++ -c Heap.cc

clean:
	rm -f *.o data_Structures
