#Makefile for my C++ Hangman game
#Last Updated: 10-14-2018

spaceadv: main.o game.o
	g++ -g -Wall -std=c++11 main.o game.o -o hangman
main.o: main.cpp
	g++ -c -std=c++11 main.cpp

game.o: game.cpp game.h
	g++ -c -std=c++11 game.cpp

clean:
	rm *.o hangman
