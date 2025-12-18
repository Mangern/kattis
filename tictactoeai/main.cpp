#include <bits/stdc++.h>
using namespace std;
using ii = array<int,2>;

// 0: E, 1: X, 2: O
using Board = array<int,9>;

map<Board, ii> best;

bool playerWon(Board board, int player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i*3]==player && board[i*3+1] == player && board[i*3+2] == player) return true;
        if (board[i] == player && board[3+i] == player && board[6+i] == player) return true;
    }
    if (board[0] == player && board[1*3+1] == player && board[2*3+2] == player) return true;
    if (board[2*3] == player && board[1*3+1] == player && board[0*3+2] == player) return true;
    return false;
}

int main() {
    Board board;

    string s;
    cin >> s;
    int player = (s == "X" ? 1 : 2);
    for (int i = 0; i < 3; ++i) {
        cin >> s;
        for (int j = 0; j < 3; ++j) {
            switch(s[j]) {
                case 'X':
                    board[i*3+j] = 1;
                    break;
                case 'O':
                    board[i*3+j] = 2;
                    break;
                case 'E':
                    board[i*3+j] = 0;
                    break;
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i*3+j] == 0) {
                Board nboard = board;
                nboard[i*3+j] = player;
                if (playerWon(nboard, player)) {
                    cout << i+1 << " " << j+1 << endl;
                    return 0;
                }
            }
        }
    }
}
