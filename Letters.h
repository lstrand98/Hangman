#ifndef LETTERS_H
#define LETTERS_H
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
//Lauren Strand, C++ Project

class Letters
{

public:

    //data member 1
    string alphabet[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    //data member 2
    char letter;      //letter inputted/guessed by user
    //data member 3
    char d = '_';
    //data member 4
    string secretWord;
    //data member 5
    char wordArray[20]; //made for display - contains underscores and correctly guessed letters


public:
    Letters();
    //method 1
    bool loadSecret(string filename);    //load file w secret word in it
    //method 2
    void printAlphabet(string alphabet[]);   //prints alphabet initially
    //method 3
    string dash(string secretWord); //prints out underscores for unguessed letters in word
    //method 4
    void inWord(char letter, string secretWord);  //verifies if letter guessed is in word. Stores letter into array if so
    //method 5
    string display(char letter, string secretWord); //prints out letters in word when guessed correctly
    //method 6
    void welcome(string filename);  //File IO - writes to file, prints out instructions/introduction
    //method 7
    string hello(string paragraph);    //strips punctuation from file



};



#endif
