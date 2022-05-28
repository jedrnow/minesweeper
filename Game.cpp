#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

chrono::milliseconds timespan(3000);

Game::Game(int x, int y, int m, string i, string w) {
    this->x = x;
    this->y = y;
    this->m = m;
    this->i = i;
    this->w = w;
}

int Game::getX() {
    return this->x;
}
int Game::getY() {
    return this->y;
}
int Game::getM() {
    return this->m;
}
string Game::getI() {
    return this->i;
}
string Game::getW() {
    return this->w;
}

void Game::askForMove() {
    int x = 0;
    int y = 0;
    cout << "Podaj koordynaty: ";
    while (x<1 || x>this->y) {
        cout << endl << "x = ";
        cin >> x;
        if (x<1 || x>this->y) {
            cout << "Nie ma takiego x. Podaj prawidlowa liczbe!";
            continue;
        }
        else {
            x = x - 1;
            break;
        }
    }
    while (y<1 || y>this->x) {
        cout << endl << "y = ";
        cin >> y;
        if (y<1 || y>this->x) {
            cout << "Nie ma takiego y. Podaj prawidlowa liczbe!";
        }
        else {
            y= y - 1;
            break;
        }
    }

    Move(x, y);

    // cin >> z zapytaniem o podanie koord -> wybuch -> update planszy -> kolejny ruch -> handle koniec gry -> zapis do statystyk
}

void Game::endGame() {
    saveStats(false);
    system("cls");
    string exploded = R"(
     ______      ___      ___   ____    ____  _  
    |_   _ \   .'   `.  .'   `.|_   \  /   _|| | 
      | |_) | /  .-.  \/  .-.  \ |   \/   |  | | 
      |  __'. | |   | || |   | | | |\  /| |  | | 
     _| |__) |\  `-'  /\  `-'  /_| |_\/_| |_ |_| 
    |_______/  `.___.'  `.___.'|_____||_____|(_) 
                                             
    )";
    system("COLOR 0C");
    cout << exploded << endl;
    this_thread::sleep_for(timespan);
    system("COLOR");
    system("cls");
}

void Game::getStats() {
    ifstream plik;
    plik.open(this->w);
    while (plik.good() != true)
    {
        cout << "Nie udalo sie zebrac statystyk!" << endl;
    }
    while(true){
        string imie;
        int wygrane;
        int przegrane;
        plik >> imie >> wygrane >> przegrane;
        if (plik.fail()) {
            break;
        }

        Player x(imie, wygrane, przegrane);
        this->playerlist.push_back(x);
    }
    plik.close();


}

void Game::saveStats(bool win) {
    ofstream plik;
    plik.open(this->w);
    while (plik.good() != true)
    {
        cout << "Nie udalo sie zapisac statystyk!";
    }
    for (int i = 0; i < playerlist.size(); i++) {
        if (playerlist[i].getName() == this->i) {
            if (win == true) {
                playerlist[i].addWin();
            }
            else {
                playerlist[i].addLose();
            }
        }
    }

    plik.clear();
    for (int i = 0; i < playerlist.size(); i++) {
        plik << playerlist[i].getName() << playerlist[i].getWin() << playerlist[i].getLose() << endl;
    }
    

    plik.close();
}


void Game::Move(int x, int y) {
    vector<Block> list = this->board.getList();
    for (int i = 0; i < list.size(); i++) {
        if (list[i].getX() == x && list[i].getY() == y) {
            if (list[i].gethasBomb() == true) {
                this->endGame();
            }
            else {
                this->board.click(i);
                this->board.Update();
                this->board.fillNumbers();
                this->board.Update();
                if (this->board.ifEnd() == true) {
                    saveStats(true);
                    system("cls");
                    std::cout << "Gratulacje wygrales!";

                }
                else {
                    askForMove();
                }
            }
        }
    }
}



void Game::StartGame() {
    getStats();
	Board board(this->x, this->y);
    this->board = board;
    board.fillNumbers();
    askForMove();
}

Game Start(int argc, char* argv[]) {
	string p1 = "-x";
    int x;
	string p2 = "-y";
    int y;
	string p3 = "-m";
    int m;
	string p4 = "-i";
    string im;
	string p5 = "-w";
    string w;


    if (argc == 12) {
        for (int i = 0; i < argc; i++) {
            if (argv[i] == p1) {
                x = atoi(argv[i + 1]);
            }
            else if (argv[i] == p2) {
                y = atoi(argv[i + 1]);
            }
            else if (argv[i] == p3) {
                m = atoi(argv[i + 1]);
            }
            else if (argv[i] == p4) {
                im = argv[i + 1];
            }
            else if (argv[i] == p5) {
                w = argv[i + 1];
                fstream plik;
                plik.open(w, std::ios::in | std::ios::out);
                while(plik.good() != true)
                {
                    cout << "Bledna sciezka do pliku ze statystykami" << endl;
                    cout << "Podaj prawidlowa sciezke: ";
                    cin >> w;
                    plik.open(w, std::ios::in | std::ios::out);
                }
             
                plik.close();
            }
        }
    }
    else {
        cout << "BLAD! Uzyj przelacznikow: -x szerokosc planszy -y wysokosc planszy -m liczba min -i imie gracza -w plik ze statystykami" << endl;
        cout << "np. program -x 20 -y 20 -m 10 -i Jacek -w statystyki.txt";
    }
    
    return Game(x, y, m, im, w);
}