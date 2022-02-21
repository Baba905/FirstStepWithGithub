all: prog
	./prog

prog: main.o Robot.o
	g++ -o prog  main.o Robot.o

Robot.o :Robot.h Robot.cpp
	g++ -c Robot.cpp -o Robot.o

main.o: Robot.h
	g++ -c main.cpp -o main.o

clear:
	rm -f *.o

zip:
	tar -zcf diopAbou-TP5.tar.gz Robot.h Robot.cpp main.cpp Robots.txt SortedRobot.txt Makefile readme.txt
	
	
