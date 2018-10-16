/*****************************************************************************************
 *** Name: Matthew Esqueda
 *** Date: October 14, 2018
 *** Description: This program is a simple game of hangman. It is made for one player.
*****************************************************************************************/

#include <iostream>
#include <stdlib.h> //Used for cout and cin
#include <string>   //Used so we can use strings
#include <time.h>   //Used for the random value
#include <vector>   //Use vectors to hold words if user chooses to upload a file since we don't know how many words the file contains
#include <fstream>  //Used to do stuff with files
#include "game.h"

int main() {
    int userChoice;     //Used to store the value of the choice the player made in the menu
    srand(time(NULL));  //Used for the random formula
    Game newGame;       //Allows one to call functions from the Game class

    std::cout << "Welcome to Hangman" << std::endl << std::endl << std::endl;

    std::cout << "Choose an option:" << std::endl;
    std::cout << "1. Play" << std::endl;
    std::cout << "2. Quit" << std::endl;
    std::cin >> userChoice;

    if(userChoice == 1)
    {
        newGame.playGame();
    }

    do{
        std::cout << "Would you like to play again?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;
        std::cin >> userChoice;

        if(userChoice == 1)
        {
            newGame.playGame();
        }
    }while(userChoice != 2);

    std::cout << "Game closing. Thank you for playing." << std::endl;

    return 0;
}