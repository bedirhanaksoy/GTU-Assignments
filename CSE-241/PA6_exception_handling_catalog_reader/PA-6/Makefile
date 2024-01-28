program: exception.o catalog.o main.o
	g++ exception.o catalog.o main.o -o program

exception.o: exception.cpp
	g++ -c exception.cpp

catalog.o: catalog.cpp
	g++ -c catalog.cpp

run:
	./program.exe

clean:
	del program.exe *.o
	