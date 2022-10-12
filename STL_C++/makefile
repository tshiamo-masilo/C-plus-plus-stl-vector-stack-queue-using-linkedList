main:main.o
	g++ -std=c++11 -static main.o -o main

main.o:main.cpp
	g++ -c -std=c++11 -static main.cpp

run:main
	./main

clean:
	rm*.o main