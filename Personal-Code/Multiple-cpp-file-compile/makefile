run:compile
	./hello
compile:main.o file1.o file2.o
	g++ -o hello main.o file1.o file2.o
main.o:main.cpp
	g++ -c main.cpp
file1.o:file1.cpp
	g++ -c file1.cpp
file2.o:file2.cpp
	g++ -c file2.cpp

