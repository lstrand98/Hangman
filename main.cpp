#include <iostream>
#include "Hangman.cpp"
#include "Letters.cpp"
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
//Lauren Strand, Karthik, Project C++

int main(){
    Hangman myhangman;

    int count = myhangman.countLines("Words.txt");
    //cout<< "Count lines: " << count << endl;
    //outputs 100 - success

    string words[count];

    myhangman.loadWords("Words.txt");
        //test if storing in array
        /*for(int j=0; j<100; j++){
            cout<< myhangman.words[j] << endl;
        }*/


    myhangman.alphabetize("Sorted.txt", words);

    string secret = myhangman.randomWord("Sorted.txt", words);
    cout<< "Secret word (when testing): " << secret << endl;

    myhangman.writeSecret("secretWord.txt");

    char letterGuess;

    Letters myletters;
    myletters.welcome("Welcome.txt");
    myletters.loadSecret("secretWord.txt");

    string ns = myletters.hello("Let's play Hangman! \nThiS wIll be fUN.");
    cout<< "Hello. " << ns << endl << endl;

    string alphabet[26];
    myletters.printAlphabet(alphabet);

    string ans;

    cout<< endl;
    cout<< "Do you want to play a game? (y/n)  ";
    cin>> ans;
    cout<< endl;
    cout<< endl;

    if(ans== "n"){
        cout<< "Goodbye." << endl;
        exit(0);
    }
    else if(ans== "y"){
        myhangman.draw(letterGuess, secret);
        myletters.dash(secret);

    }
    while(ans!="y" && ans!="n"){
        cout<< "Enter in 'y' or 'n' ";
        cin>> ans;
        if(ans=="y"){
            myhangman.draw(letterGuess, secret);
            myletters.dash(secret);
        }
        if(ans=="n"){
            cout<< "Goodbye." << endl;
            exit(0);
        }
    }

    while(myhangman.isGameOver(secret)==false){
        cout<< "Input a lowercase letter to guess: ";
        cin>> letterGuess;
        if(letterGuess>=65 && letterGuess<=90){
        letterGuess = tolower(letterGuess); }
        cout<< endl;
        myhangman.lettersGuessed(letterGuess);
        myhangman.printHangman(letterGuess, secret);
        cout<< endl;
        myletters.display(letterGuess, secret);
        myhangman.fullWord(letterGuess, secret);

    }



}
