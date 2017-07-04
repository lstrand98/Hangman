#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h> //srand, rand
#include "Hangman.h"
using namespace std;
//Lauren Strand, Karthik, Project C++

Hangman::Hangman(){
    //initialization
    for(int i=0; i<100; i++){
        letters_in[i] = '0';
    }
}


int Hangman::countLines(string filename){
    ifstream dataFile;
    dataFile.open(filename.c_str());
    if(!dataFile.is_open()){
        cout<< "File open error!" << endl;
        return 0;
    }
    int count = 0;
    string line;
    while(getline(dataFile, line)){
        count++;
    }
    return count;
    dataFile.close();
}

bool Hangman::loadWords(string filename){
    ifstream dataFile;
    dataFile.open(filename.c_str());
    if(dataFile.fail())
        return false;
    string line;
    count = 0;
    while(getline(dataFile, line)){
        words[count] = line;
        count++;
    }
    return true;
    dataFile.close();


}

void Hangman::alphabetize(string filename, string a[]){
    ofstream dataFile;
    dataFile.open(filename.c_str());

    //bubble sort to alphabetize
    for(int i=0; i<count; i++){
        int big = i;
        for(int j=i; j<count; j++){
            if(words[big] > words[j]){
                big = j;
            }
        }
        //swap
        string w = words[i];
        words[i] = words[big];
        words[big] = w;
    }

    for(int i=0; i<count; i++){
        dataFile << words[i] << endl;
        //write words in array to file
            //test
            //cout<< words[i] << endl;
    }
    dataFile.close();
}

string Hangman::randomWord(string filename, string a[]){
    srand(time(NULL));
    //destruction of random generator memory (storing it for only certain amount of time)
    //srand used to set starting value (seed) for generating pseudo random int values
    //time(NULL) uses computer's internal clock to control choice of seed
        //since time continually changing, seed always changing
        //if time null not there, program spits out same number every time (because seed number remains same)
    secretNum = rand() % count +1;
    //generate random number from index 1 to count=100
    //rand()%n produces value in range of 0 - (n-1)
    //rand function based off of equation. When given seed, always generates same sequence of numbers
        //srand changes seed value
    //rand computes random number, mod returns remainder
    secretWord = words[secretNum];
    //use random number as index in words array
    return secretWord;
}

void Hangman::writeSecret(string filename){
    ofstream dataFile;
    dataFile.open(filename.c_str());
    dataFile << secretWord << endl;
    dataFile.close();
    //write secret word into file
}

bool Hangman::lettersGuessed(char l2){
    inL = false;
    //searching through array
    for(int i=0; i<100; i++){
        if (l2 == letters_in[i]){
            cout<< "Repeat. Guess again" << endl;
            inL = true; //in array already
            break;
        }
    }
     //adding to array
    if(inL==false){
        //if not in array
        letters_in[index] = l2;
        //store that letter into array
        index++;
    }
    return inL;
    //bool either true or false, different in different functions
    //data member so not overwritten when called by multiple functions, 'cleared'
    //if no inL and just 'return false' (or true), only works for one function since bool value not same for multiple functions
}


bool Hangman::inWord(char l2, string sW){
    for(int i=0; i<sW.length(); i++){
        if(l2 == sW[i]){
            return true;
            //if letter guessed in word
        }
    }
    return false;
}

int Hangman::fullWord(char l2, string sW){
    for(int i=0; i<sW.length(); i++){
        if(l2 == sW[i] && !inL){
            correct++;
            //count correctly guessed letters
        }
    }
    return correct;
}

int Hangman::wrongGuesses(char l2, string sW){
    if(inWord(l2, sW)==false && !inL){
        wrong++;
        //count guessed letters that are not in the word
        cout<< "Not in word" << endl;
    }
    return wrong;
}


void Hangman::draw(char l2, string sW){
    cout << "________" << endl;
    cout<< "|" << "      " << "|" << endl;
    cout<< "       " << "|" << endl;
    cout<< "       " << "|" << endl;
    cout<< "       " << "|" << endl;
    cout<< "       " << "|" << endl;
    cout<< "       " << "|" << endl;
    cout<< "     " << "__" << "|" << "___" << endl;


}


void Hangman::printHangman(char l2, string sW){
    int w = wrongGuesses(l2, sW);

    if((w == 1) && (!inL)){
        //1 wrong guess made and letter not already guessed, print out the following
        cout << " ________" << endl;
        cout<< " |" << "      " << "|" << endl;
        cout<< " "<<bodyParts[0];
        cout<< "      " << "|" << endl;
        cout<< "        " << "|" << endl;
        cout<< "        " << "|" << endl;
        cout<< "        " << "|" << endl;
        cout<< "        " << "|" << endl;
        cout<< "      " << "__" << "|" << "___" << endl;
    }

    else if((w==2) && (!inL)){
        //2 wrong guesses made, letter not previously guessed
        cout << " ________" << endl;
        cout<< " |" << "      " << "|" << endl;
        cout<< " "<<bodyParts[0];
        cout<< "      " << "|" << endl;
        cout<< " "<<bodyParts[1];
        cout<< "      " << "|" << endl;
        cout<< "        " << "|" << endl;
        cout<< "        " << "|" << endl;
        cout<< "        " << "|" << endl;
        cout<< "      " << "__" << "|" << "___" << endl;
    }

    else if((w==3) && (!inL)){
        cout << " ________" << endl;
        cout<< " |" << "      " << "|" << endl;
        cout<< " "<<bodyParts[0];
        cout<< "      " << "|" << endl;
        cout<< bodyParts[2];
        cout<< bodyParts[1];
        cout<< "      " << "|" << endl;
        cout<< "        " << "|" << endl;
        cout<< "        " << "|" << endl;
        cout<< "        " << "|" << endl;
        cout<< "      " << "__" << "|" << "___" << endl;
    }

    else if((w==4) && (!inL)){
        cout << " ________" << endl;
        cout<< " |" << "      " << "|" << endl;
        cout<< " "<<bodyParts[0];
        cout<< "      " << "|" << endl;
        cout<< bodyParts[2];
        cout<< bodyParts[1];
        cout<< bodyParts[3];
        cout<< "     " << "|" << endl;
        cout<< "        " << "|" << endl;
        cout<< "        " << "|" << endl;
        cout<< "        " << "|" << endl;
        cout<< "      " << "__" << "|" << "___" << endl;
    }
    else if((w==5) && (!inL)){
        cout << " ________" << endl;
        cout<< " |" << "      " << "|" << endl;
        cout<< " "<<bodyParts[0];
        cout<< "      " << "|" << endl;
        cout<< bodyParts[2];
        cout<< bodyParts[1];
        cout<< bodyParts[3];
        cout<< "     " << "|" << endl;
        cout<< bodyParts[4];
        cout<< "       " << "|" << endl;
        cout<< "        " << "|" << endl;
        cout<< "        " << "|" << endl;
        cout<< "      " << "__" << "|" << "___" << endl;
    }

     else if((w==6) && (!inL)){
        //6 wrong guesses made (max)
        cout << " ________" << endl;
        cout<< " |" << "      " << "|" << endl;
        cout<< " "<<bodyParts[0];
        cout<< "      " << "|" << endl;
        cout<< bodyParts[2];
        cout<< bodyParts[1];
        cout<< bodyParts[3];
        cout<< "     " << "|" << endl;
        cout<< bodyParts[4];
        cout<< " " <<bodyParts[5];
        cout<< "     " << "|" << endl;
        cout<< "        " << "|" << endl;
        cout<< "        " << "|" << endl;
        cout<< "      " << "__" << "|" << "___" << endl;
        cout<< "You lose. Game over";
    }
}

bool Hangman::isGameOver(string sW){
    if(wrong==6){
        return true;
    }
    //if wrong guesses=6 game is over
    else if(correct == (int)sW.length()){
        //if number correctly guessed letters = length of word (word 'full')
        cout<< "You won!";
        //win game
        return true;
    }
    return false;
}

