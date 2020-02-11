main: fraction.o main.o point.o
	g++ -o main fraction.cc main.cc point.cc

fraction.o: fraction.cc fraction.h
	g++ -c fraction.cc

main.o: main.cc fraction.h point.h
	g++ -c main.cc

point.o: point.cc point.h
	g++ -c point.cc
