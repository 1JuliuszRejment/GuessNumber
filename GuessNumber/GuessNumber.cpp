
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;


void addScore(string name, int numberOfGuess) {
    ofstream scoreFile;
    scoreFile.open("scoreBoard.txt", ios::app);
    if (scoreFile.is_open()) {
        string data;
        data = name + ';' + to_string(numberOfGuess);
        scoreFile << data << "\n";
        scoreFile.close();
    }
}


void game(string name) {
    system("cls");
    cout << "Witaj " << name << " w grze chodzi aby jak najszybciej odgadnac liczbe od 1 do 100.\nZaczynamy!!!\n";
    srand(time(0));

    int numberToGuess = rand() % 100 + 1;
    int numberOfGuess = 1;
    int guessNumber;
    bool gameOn = true;

    while (gameOn) {
        cout << "O jakiej liczbie mysle: ";
        cin >> guessNumber;
        if (guessNumber == numberToGuess)
        {
            cout << "Brawo zgadles w " << numberOfGuess << " prob\n";
            addScore(name, numberOfGuess);
            gameOn = false;
        }
        else if (guessNumber > numberToGuess)
        {
            cout << "Za duzo!\n";
        }
        else if (guessNumber < numberToGuess)
        {
            cout << "Za malo!\n";
        }
        else
        {
            cout << "Podane dane sa niepoprawne\n";
        }
        numberOfGuess++;
    }
}

void scoreBoard() {
    ifstream scoreFile;
    string scoreBoardData;

    scoreFile.open("scoreBoard.txt", ios::in);
    if (scoreFile.is_open()) {
        while (getline(scoreFile, scoreBoardData)) {
            cout << scoreBoardData << "\n";
        }
        scoreFile.close();
    }
    
    getchar();
}

int main()
{
    string name;
    cout << "Welcome in GuessGame!!!\n";
    cout << "Aby rozpoczac wpisz swoje imie: ";
    cin >> name;
    int userInput;

    bool gameOn = true;
    while (gameOn) {
        cout << "MENU\n 1. Graj\n 2. Ranking\n 3. Zmien nazwe\n 4. Wyjscie\nCo chcesz zrobic(1-4): ";
        cin >> userInput;
        system("cls");
        switch (userInput)
        {
        case 1:
            game(name);
            break;
        case 2:
            scoreBoard();
            break;
        case 3:
            cout << "Podaj nowe imie: ";
            cin >> name;
            break;
        case 4:
            gameOn = false;
            break;
        }

    }
    
    return 0;
}