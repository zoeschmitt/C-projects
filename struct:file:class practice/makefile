#makefile for Time class with three files:
# TimeStamp.h, TimeStamp.cpp, Driver.cpp

a.out: Driver.o Player.o TimeStamp.o
	g++ Driver.o Player.o TimeStamp.o

Driver.o: Driver.cpp TimeStamp.h
	g++ -std=c++11   -c Driver.cpp

Player.o: Player.cpp Player.h 
	g++ -std=c++11 -c Player.cpp

TimeStamp.o: TimeStamp.cpp TimeStamp.h
	g++ -std=c++11 -c  TimeStamp.cpp

