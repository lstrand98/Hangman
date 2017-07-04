//Lauren Strand, Karthik, Project C++
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Letters.h"
using namespace std;

Letters::Letters(){
    //initialize array to underscores
    for(int j=0; j<secretWord.length(); j++){
        wordArray[j] = d;
    }
}


bool Letters::loadSecret(string filename){
    ifstream dataFile;
    dataFile.open(filename.c_str());
    if(dataFile.fail()){
        return false;
    }
    string line;
    while(getline(dataFile, line)){
        secretWord = line;
    }
    /*test
    cout<< secretWord; */
    return true;
    dataFile.close();
}

void Letters::printAlphabet(string b[]){
    for(int i=0; i<26; i++){
        cout<< alphabet[i]<< " ";
    }

}

string Letters::dash(string sW){
    for(int i=0; i<sW.length(); i++){
        wordArray[i] = d;
        cout<< wordArray[i] << " ";
    }
    //prints out underscore for each unknown/unguessed letter
}

void Letters::inWord(char l, string sW){  //l is letter, sW is secretWord
    for(int i=0; i<sW.length(); i++){
        if(l == sW[i]){
        //if letter guessed is in the word
            wordArray[i] = l;
            //store letter into array at that same index as in word
        }
    }

}

string Letters::display(char l, string sW){
    inWord(l, sW);
    //if letter in word, get that index in array
    for(int i=0; i<(int)sW.length(); i++){
        cout<< wordArray[i]<< " ";
        //and print it out
    }
}

void Letters::welcome(string filename){
    ofstream outFile;
    outFile.open(filename.c_str());
    if(outFile.fail()){
        cout<< "Cannot open. Error.";
    }
    outFile<<"Hello user! Let's play Hangman! The computer will randomly generate a word, and you will have to guess the word by inputting letters. Letters cannot be" << endl;
    outFile<< "repeated; if a letter is repeated, it will not count against you. The program will let you know, though, when a letter is repeated. If the letter is" << endl;
    outFile<< "in the hidden/randomly generated word, it will appear in its appropriate index within the word. If the letter guessed is incorrect, a body part of the" << endl;
    outFile<< "hangman will be displayed. The game is over once the word is guessed and all letters are revealed (win) or when all the body parts of the hangman are displayed (lose)." << endl;
    outFile<< "Good luck, and happy guessing!";
    outFile.close();
}

string Letters::hello(string paragraph){
    string word;
    string lower;
    string new_s = "";
    istringstream ss(paragraph);
    while(getline(ss, word, ' ')){
        lower = "";
        for(int i=0; i<(int)word.length(); i++){
            lower += toupper(word[i]);
        }
        new_s += lower + " ";
    }
    return new_s;
}
