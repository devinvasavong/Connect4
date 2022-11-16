// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: Connect4
// Course: Computational Problem Solving I (CPET-121)
// Developer: Devin Vasavong (Computer Engineering Technology)
// Date: November 1, 2022
// Description: 2 player Connect4. Starting player is chosen at random.
//              A player must have either a vertical, horizontal, or diagonal
//              of four corresponding to win.
// Note: I coded this on Mac. Features, such as system() have not been used.
//      The terminal will not be cleared after each move due to that.
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <iomanip>
#include <vector>

#define ROW 6
#define COL 7

using namespace std;

// Function Prototypes
int displayStart();
void displayGraph(int);
char intToLetter(int);`
int switchPlayer(int);

int main() {

    int player = displayStart();

    if(player) {
        displayGraph(player);
    }

    return 0;
}


// Introduction screen with key to confirm

int displayStart() {

    int player;

    cout << "           Welcome to Connect4" << endl;
    cout << "   The goal of Connect4 is to be the first" << endl;
    cout << "player to place four checkers in a row, either" << endl;
    cout << "   horizontally, vertically or diagonally." << endl;

    srand(time(NULL));
    player = (rand() % 2) + 1;

    cout << endl << endl;

    if(player == 1) {
        cout << "Player #1 was selected to go first";
    } else if(player == 2) {
        cout << "Player #2 was selected to go first";
    }

    cout << endl;
    cout << "Press ENTER to continue...";
    getchar(); // Mac way of system("PAUSE")

    return player;
}

// Display graph, main game
void displayGraph(int player) {

    int integers[ROW][COL] = { 0, 0, 0, 0, 0, 0,0,
                               0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0 };
    bool winner = false;
    bool gameInPlay = true;
    bool contPlay = true;
    int wins[2] = {0, 0};
    char option;

    // Contplay for player decision if want to play again
    while(contPlay == true) {

        // Display numbers above graph
        for (int i = 1; i <= 7; i++) {
            cout << "   " << i;
        }
        cout << endl;

        cout << "------------------------------" << endl;
        for(int i = 0; i < ROW; i++) {
            cout << "|";
            for(int j = 0; j < COL; j++) {
                if(integers[i][j] != 0) {
                    cout << setw(3) << "" << intToLetter(integers[i][j]);
                } else {
                    cout << setw(4) << "";
                }
            }
            cout << "|";
            cout << endl;
            cout << "------------------------------" << endl;
        }

        if (player == 1) {
            cout << "Player #" << player << "'s Turn (X) : Enter Your Move : ";
        } else if (player == 2) {
            cout << "Player #" << player << "'s Turn (O) : Enter Your Move : ";
        }

        int column;
        cin >> column;

        while (column < 1 || column > 7) {
            cout << "Illegal Position, Please Reenter" << endl;
            if (player == 1) {
                cout << "Player #" << player << "'s Turn (X) : Enter Your Move : ";
            } else if (player == 2) {
                cout << "Player #" << player << "'s Turn (O) : Enter Your Move : ";
            }
            cin >> column;
        }


        column = column - 1;

        if(integers[0][column] != 0) {
            cout << "Move Not Available, You Lost Your Turn" << endl;
        } else {
            for (int i = ROW - 1; i >= 0; i--) {
                if (integers[i][column] == 0) {
                    integers[i][column] = player;
                    break;
                }
            }
        }

        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                if (integers[i][j] == player && // Vertical win
                    integers[i + 1][j] == player &&
                    integers[i + 2][j] == player &&
                    integers[i + 3][j] == player) {
                    cout << "------------------------------" << endl;
                    for (int i = 0; i < ROW; i++) {
                        cout << "|";
                        for (int j = 0; j < COL; j++) {
                            if (integers[i][j] != 0) {
                                cout << setw(3) << "" << intToLetter(integers[i][j]);
                            } else {
                                cout << setw(4) << "";
                            }
                        }
                        cout << "|";
                        cout << endl;
                        cout << "------------------------------" << endl;
                    }
                    winner = true;
                    cout << "Player #" << player << " Was The Winner (Vertically)" << endl;

                    if (player == 1) {
                        wins[0] = wins[0] + 1;
                    } else if (player == 2) {
                        wins[1] = wins[1] + 1;
                    }
                } else if (integers[i][j] == player && // Horizontal win
                           integers[i][j + 1] == player &&
                           integers[i][j + 2] == player &&
                           integers[i][j + 3] == player) {
                    cout << "------------------------------" << endl;
                    for (int i = 0; i < ROW; i++) {
                        cout << "|";
                        for (int j = 0; j < COL; j++) {
                            if (integers[i][j] != 0) {
                                cout << setw(3) << "" << intToLetter(integers[i][j]);
                            } else {
                                cout << setw(4) << "";
                            }
                        }
                        cout << "|";
                        cout << endl;
                        cout << "------------------------------" << endl;
                    }
                    winner = true;
                    cout << "Player #" << player << " Was The Winner (Horizontally)" << endl;

                    if (player == 1) {
                        wins[0] = wins[0] + 1;
                    } else if (player == 2) {
                        wins[1] = wins[1] + 1;
                    }
                }
            }
        }

        for(int i = 0; i < (COL-3); i++){
            for(int j = 0; j < (ROW-3); j++) {
                if(integers[i][j] == player && // Diagonal win
                    integers[i+1][j+1] == player &&
                    integers[i+2][j+2] == player &&
                    integers[i+3][j+3] == player ||
                    integers[i+3][j] == player &&
                    integers[i+2][j+1] == player &&
                    integers[i+1][j+2] == player &&
                    integers[i][j+3] == player
                    ) {
                    cout << "------------------------------" << endl;
                    for (int i = 0; i < ROW; i++) {
                        cout << "|";
                        for (int j = 0; j < COL; j++) {
                            if (integers[i][j] != 0) {
                                cout << setw(3) << "" << intToLetter(integers[i][j]);
                            } else {
                                cout << setw(4) << "";
                            }
                        }
                        cout << "|";
                        cout << endl;
                        cout << "------------------------------" << endl;
                    }
                    cout << "Player #" << player << " Was The Winner (Diagonally)" << endl;
                    winner = true;
                }
            }
        }

        player = switchPlayer(player);

        if(winner == true) {

            cout << "Would you like to play again? [Y/N] ";
            cin >> option;

            if (tolower(option) == 'y') {
                winner = false;

                for(int i = 0; i < ROW; i++) {
                    for(int j = 0; j < COL; j++) {
                        integers[i][j] = 0;
                    }
                }

                for(int i = 0; i < ROW; i++) {
                    for(int j = 0; j < COL; j++) {
                        cout << integers[i][j] << " ";
                    }
                    cout << endl;
                }

                contPlay = true;
            } else if (tolower(option) == 'n') {
                cout << "Player #1: " << wins[0] << " wins" << endl;
                cout << "Player #2: " << wins[1] << " wins" << endl;
                contPlay = false;
            }
        } else {
            int zeros = 0;
            for(int i = 0; i < ROW; i++) {
                for(int j = 0; j < COL; j++) {
                    if(integers[i][j] == 0) {
                        zeros++;
                    }
                }
            }
            if(zeros == 0 && winner == false) {
                for (int i = 0; i < ROW; i++) {
                    cout << "|";
                    for (int j = 0; j < COL; j++) {
                        if (integers[i][j] != 0) {
                            cout << setw(3) << "" << intToLetter(integers[i][j]);
                        } else {
                            cout << setw(4) << "";
                        }
                    }
                    cout << "|";
                    cout << endl;
                    cout << "------------------------------" << endl;
                }
                cout << "The Game Ended In A Tie" << endl;

                cout << "Would you like to play again? [Y/N] ";
                cin >> option;

                if (tolower(option) == 'y') {
                    winner = false;

                    for(int i = 0; i < ROW; i++) {
                        for(int j = 0; j < COL; j++) {
                            integers[i][j] = 0;
                        }
                    }

                    for(int i = 0; i < ROW; i++) {
                        for(int j = 0; j < COL; j++) {
                            cout << integers[i][j] << " ";
                        }
                        cout << endl;
                    }

                    contPlay = true;
                } else if (tolower(option) == 'n') {
                    cout << "Player #1: " << wins[0] << " wins" << endl;
                    cout << "Player #2: " << wins[1] << " wins" << endl;
                    contPlay = false;
                }

            }
        }

    }

}

char intToLetter(int player) {
    if(player == 1) {
        return 'x';
    } else if(player == 2) {
        return 'o';
    }
}

int switchPlayer(int player) {
    if(player == 1) {
        return 2;
    } else if(player == 2) {
        return 1;
    }
}
