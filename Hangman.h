#ifndef HANGMAN_H
#define HANGMAN_H
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
//Lauren Strand, C++ Project

class Hangman
{
public:
    //data members
    char head = 'O';
    char body = '|';
    char arm1 = '/';
    char arm2 = '\\';
    char leftLeg = '/';
    char rightLeg = '\\';
    char bodyParts[6] = {head, body, arm1, arm2, leftLeg, rightLeg};
    string words[100];
    int count = 0;
    char letter2;   //guessed letter (input)
    int wrong = 0;  //wrong guesses
    int correct = 0;    //letters in word, guessed
    char letters_in[100];   //all words cin
    int index = 0;
    bool inL;   //in letters_in array



private:
    int secretNum;  //used in random generator
    string secretWord;  //randomly generated word

//Methods
public:
    Hangman();  //default constructor
    //method 1
    int countLines(string filename);    //read file in, one word per line
    //method 2
    bool loadWords(string filename);    //load file of words to use in random generator, stores words into array
    //method 3
    void alphabetize(string filename, string words[]);  //File IO - write out, alphabetize list
    //method 4
    string randomWord(string filename, string words[]); //generates random word, to be secretWord
    //method 5
    void writeSecret(string filename);  //File IO - write out, writes secret word in different file
    //method 6
    bool lettersGuessed(char letter2);  //keeps track of repeated letters. Function referenced by fullWord & printHangman
    //method 7
    bool inWord(char letter2, string secretWord);   //check if letter guessed in secret word
    //method 8
    int fullWord(char letter2, string secretWord);  //counts number of correctly guessed letters (in word)
    //method 9
    int wrongGuesses(char letter2, string secretWord);  //counts number of guessed letters not in word
    //method 10
    void draw(char letter2, string secretWord); //draws initial hangman graphic
    //method 11
    void printHangman(char letter2, string secretWord); //prints out body part each time guessed letter not in word
    //method 12
    bool isGameOver(string secretWord); //if all body parts printed out or all letters correctly guessed, game over


};



#endif // HANGMAN_H
