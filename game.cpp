//
// Created by Matthew Esqueda on 9/6/18.
//

#include "game.h"

//Default constructor
Game::Game() {
    defaultWords= {
            "baseball",
            "football",
            "hockey",
            "mickey",
            "lightspeed",
            "computer",
            "mission",
            "therapist",
            "history",
            "keyboard"
    };
    numOfWrongGuesses = 0;          //Keeps track of how many wrong guesses are made
    maxGuesses = 6;                 //The max amount of guesses a user gets per game
    unsigned long random;           //Used to select a random index of the array or vector
    std::ifstream inputFile;        //Used to read a file
    std::string fileName;           //Used to store the name of the file the user wants to open
    std::string fileWords;          //Used to hold the words read from the file
    std::string randomWord;         //Holds the random word that is chosen from the file or the built in vector
    char guess;                     //Holds the letter the player is guessing
    std::vector<std::string> word;  //Used to create the vector that holds the words from the file the user uploads
    std::vector<char> guessedWord;
}

/*******************************************************
***Function that plays the game until the user guesses the word or they run out of guesses
***Parameter: None
***Return: No return value
*********************************************************/
void Game::playGame() {

    int userChoice;
    int letterFound = 0;
    int correctGuesses;

    std::cout << "Would you like to upload a file or use the built in choice of words?" << std::endl;
    std::cout << "1. Upload File" << std::endl;
    std::cout << "2. House Words" << std::endl;
    std::cin >> userChoice;

    if(userChoice == 1) //Play with words from a file the user uploads
    {
        //Ask user to enter the name of the file they want to upload
        std::cout << "Please enter the name of the file you wish to upload:" << std::endl;
        std::cin >> fileName;

        //Open the file
        inputFile.open(fileName);

        //Pass the words in the file into a vector
        if(inputFile)
        {
            while(inputFile >> fileWords)
            {
                word.push_back(fileWords);
            }
        }

        //Randomly choose a word from the vector
        random = rand() % word.size();

        randomWord = word.at(random);

        //Pass the characters of the word into a vector of chars
        std::vector<char> playWord(randomWord.begin(), randomWord.end());

        //Enter commas(,) into guessedWord
        for(int i=0; i<playWord.size(); i++)
        {
            guessedWord.push_back(',');
        }

        correctGuesses = playWord.size();

        //User keeps guessing letters until they find the word or they run out of guesses
        while(numOfWrongGuesses != 6 && correctGuesses != 0)
        {
            for(int i=0; i<guessedWord.size(); i++)
            {
                std::cout << guessedWord[i];
            }

            std::cout << std::endl;

            //Tell the user how many guesses they have
            std::cout << "Guesses still left: " << maxGuesses - numOfWrongGuesses << std::endl;

            //Have the user guess a letter
            std::cout << "Enter a letter: " << std::endl;

            std::cin >> guess;

            //Check to see if the letter is in the word
            for(int i=0; i<playWord.size(); i++)
            {
                //If the letter is there then update game board and remove letter from vector
                if(guess == playWord.at(i))
                {
                    std::cout << "Good job. You found a letter." << std::endl;

                    //auto itr = std::find(playWord.begin(), playWord.end(), guess);

                    //Change letterFound value to 1
                    letterFound = 1;

                    //Remove letter from playWord vector and replace it with a ,
                    playWord[i] = ',';
                    //playWord.erase(itr);

                    //Add letter to guessedWord
                    guessedWord[i] = guess;

                    //Subtract one from correctGuesses
                    correctGuesses--;

                    //Break out of the loop
                    break;
                }
            }

            //If the letter is not there then update game board, add one to numOfWrongGuesses, tell user incorrect
            if(letterFound == 0)
            {
                std::cout << "Sorry. That letter is not in the word." << std::endl;

                numOfWrongGuesses++;
            }

            letterFound = 0;
        }

        gallows(numOfWrongGuesses);
    }
    else //Play with the words built into the program
    {
        //Randomly choose a word from the built in vector
        random = rand() % defaultWords.size();

        randomWord = defaultWords.at(random);

        //std::cout << randomWord << std::endl;

        //Pass the characters of the word into a vector of chars
        std::vector<char> playWord(randomWord.begin(), randomWord.end());

        //Enter commas(,) into guessedWord
        for(int i=0; i<playWord.size(); i++)
        {
            guessedWord.push_back(',');
        }

        correctGuesses = playWord.size();

        //User keeps guessing letters until they find the word or they run out of guesses
        while(numOfWrongGuesses != 6 && correctGuesses != 0)
        {
            //Display the game board
            gallows(numOfWrongGuesses);

            for(int i=0; i<guessedWord.size(); i++)
            {
                std::cout << guessedWord[i];
            }

            std::cout << std::endl;

            //Tell the user how many guesses they have
            std::cout << "Guesses still left: " << maxGuesses - numOfWrongGuesses << std::endl;

            //Have the user guess a letter
            std::cout << "Enter a letter: " << std::endl;

            std::cin >> guess;

            //Check to see if the letter is in the word
            for(int i=0; i<playWord.size(); i++)
            {
                //If the letter is there then update game board and remove letter from vector
                if(guess == playWord.at(i))
                {
                    std::cout << "Good job. You found a letter." << std::endl;

                    //auto itr = std::find(playWord.begin(), playWord.end(), guess);

                    //Change letterFound value to 1
                    letterFound = 1;

                    //Remove letter from playWord vector and replace it with a ,
                    playWord[i] = ',';
                    //playWord.erase(itr);

                    //Add letter to guessedWord
                    guessedWord[i] = guess;

                    //Subtract one from correctGuesses
                    correctGuesses--;

                    //Break out of the loop
                    break;
                }
            }

            //If the letter is not there then update game board, add one to numOfWrongGuesses, tell user incorrect
            if(letterFound == 0)
            {
                std::cout << "Sorry. That letter is not in the word." << std::endl;

                numOfWrongGuesses++;
            }

            letterFound = 0;
        }

        gallows(numOfWrongGuesses);
    }

    //Reset numOfWrongGuesses
    numOfWrongGuesses = 0;

    //Reset guessedWord vector
    guessedWord.clear();
}

/*******************************************************
***Function for printing the gallows
***Parameter: Takes an int value to determine what to print
***Return: No return value
*********************************************************/
void Game::gallows(int wrongGuesses)
{
    //Print just the gallows
    if(wrongGuesses == 0)
    {
        std::cout << "_________________           " << std::endl;
        std::cout << "|                |          " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|_____________              " << std::endl << std::endl;
    }
    //Print the head
    else if(wrongGuesses == 1)
    {
        std::cout << "_________________           " << std::endl;
        std::cout << "|                |          " << std::endl;
        std::cout << "|                O          " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|_____________              " << std::endl << std::endl;
    }
    //Print the body
    else if(wrongGuesses == 2)
    {
        std::cout << "_________________           " << std::endl;
        std::cout << "|                |          " << std::endl;
        std::cout << "|                O          " << std::endl;
        std::cout << "|                |          " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|_____________              " << std::endl << std::endl;
    }
    //Print the left arm
    else if(wrongGuesses == 3)
    {
        std::cout << "_________________           " << std::endl;
        std::cout << "|                |          " << std::endl;
        std::cout << "|                O          " << std::endl;
        std::cout << "|               /|          " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|_____________              " << std::endl << std::endl;
    }
    //Print the right arm
    else if(wrongGuesses == 4)
    {
        std::cout << "_________________           " << std::endl;
        std::cout << "|                |          " << std::endl;
        std::cout << "|                O          " << std::endl;
        std::cout << "|               /|\\        " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|_____________              " << std::endl << std::endl;
    }
    //Print the left leg
    else if(wrongGuesses == 5)
    {
        std::cout << "_________________           " << std::endl;
        std::cout << "|                |          " << std::endl;
        std::cout << "|                O          " << std::endl;
        std::cout << "|               /|\\        " << std::endl;
        std::cout << "|               /           " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|_____________              " << std::endl << std::endl;
    }
    //Print entire person - game over
    else if(wrongGuesses == 6)
    {
        std::cout << "_________________           " << std::endl;
        std::cout << "|                |          " << std::endl;
        std::cout << "|                O          " << std::endl;
        std::cout << "|               /|\\        " << std::endl;
        std::cout << "|               / \\        " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|                           " << std::endl;
        std::cout << "|_____________              " << std::endl << std::endl;
    }
}