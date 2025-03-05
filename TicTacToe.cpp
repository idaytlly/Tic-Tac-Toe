#include <iostream>
#include <ctime>
using namespace std;

void drawGrid ( char *empty);
void playerTurn (char *empty, char player);
void computerTurn ( char *empty, char computer);
bool findWinner (char *empty, char player);
bool findTie (char *empty);

int main (){
char empty[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
char player = 'X';
char computer = 'O';
bool running = true;

while (running){
    playerTurn (empty, player);
    drawGrid (empty);
    if (findWinner (empty, player)){
       running = false;
        break;
    } else if (findTie(empty)){
        running = false;
        break;
    }

    computerTurn (empty, computer);
    drawGrid (empty);
    if (findWinner (empty, player)){
        running = false;
        break;
    } else if (findTie(empty)){
        running = false;
        break;
    }
}
    return 0;
}
void drawGrid ( char *empty){
    std::cout << "     |     |     \n";
    std::cout << "    " << empty[0]<< "|    "<< empty[1] << "|    " << empty[2] << '\n';
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "    " << empty[3]<< "|    "<< empty[4] << "|    " << empty[5] << '\n';
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "    " << empty[6] << "|    "<< empty[7] << "|    " << empty[8] << '\n';
    std::cout << '\n';
}
void playerTurn (char *empty, char player){
    int number;
    do {
        std::cout << "Enter the grid you want to mark (1-9): ";
        cin >> number;
        number--;
        if (empty[number] ==' '){
            empty[number] = player;
            break;
        }
    } while (!number > 0 && !number < 8);
}
void computerTurn (char *empty, char computer){
    int number;
    srand(time(0));

    while (true) {
        number = rand() % 9;
    if (empty[number] == ' '){
        empty[number] = computer;
        break;
        }
    }
}


bool findWinner (char *empty, char player){
    if ((empty[0] != ' ') && (empty[0] == empty[1]) && (empty[1] == empty [2])){
        empty[0] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!" ;
    }
    else if ((empty[3] != ' ') && (empty[3] == empty[4]) && (empty[4] == empty [5])){
        empty[3] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
    }
    else if ((empty[6] != ' ') && (empty[6] == empty[7]) && (empty[7] == empty [8])){
        empty[6] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
    }
    else if ((empty[0] != ' ') && (empty[0] == empty[4]) && (empty[4] == empty [8])){
        empty[0] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
    }
    else if ((empty[1] != ' ') && (empty[1] == empty[4]) && (empty[4] == empty [6])){
        empty[1] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
    }
    else {
        return false;
    }
    return true;
}
bool findTie (char *empty){
    for (int i=0; i<9; i++){
        if (empty[i] == ' '){
            return false;
        }
    }
    std::cout << "IT'S A TIE!";
    return true;
}