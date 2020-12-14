main: my_int.o	main.o
	g++ -Wall my_int.o main.o -o main

my_int.o: my_int.cc my_int.h
	g++ -Wall -c my_int.cc

main.o: main.cc my_int.h
	g++ -Wall -c main.cc

clean:
	rm -f *.o a.out