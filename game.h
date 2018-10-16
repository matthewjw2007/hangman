//
// Created by Matthew Esqueda on 9/6/18.
//

#ifndef HANGMAN_GAME_H
#define HANGMAN_GAME_H
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>  //Used to do stuff with files

class Game {
private:
    std::vector <std::string> defaultWords;
    int numOfWrongGuesses;          //Keeps track of how many wrong guesses are made
    int maxGuesses;                 //The max amount of guesses a user gets per game
    unsigned long random;           //Used to select a random index of the array or vector
    std::ifstream inputFile;        //Used to read a file
    std::string fileName;           //Used to store the name of the file the user wants to open
    std::string fileWords;          //Used to hold the words read from the file
    std::string randomWord;         //Holds the random word that is chosen from the file or the built in vector
    char guess;                     //Holds the letter the player is guessing
    std::vector<std::string> word;  //Used to create the vector
    //std::vector<char> playWord;     //Vector that holds the characters from the random chosen word
    std::vector<char> guessedWord;

public:
    Game(); //Default constructor
    void playGame(); //Function to start and play the game
    void gallows(int);  //Function that returns the current state of the gallows(hangman)
};


#endif //HANGMAN_GAME_H
