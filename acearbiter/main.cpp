#include <bits/stdc++.h>
using namespace std;
using ii = array<int,2>;

int check(int n, vector<ii> score) {

    if (n == 1) {
        if (score[0][0] == 11 && score[0][1] == 11) {
            return 1;
        } else {
            return 0;
        }
    }

    int px = 0, py = 0;

    int msm = 40;
    for (int i = 0; i < n; ++i) {
        int x = score[i][0];
        int y = score[i][1];
        if (x+y < px+py) {
            //cout << "error " << i+1 << endl;
            return i+1;
        }

        bool cs = ((x+y+3)%4)>=2;


        if (cs)swap(x,y);

        if (x < px || y < py) {
            return i+1;
        }

        if (x+y > msm) {
            return i+1;
        }

        if (max(x,y) == 11)msm = x+y;

        px = x;
        py = y;
    }

    return 0;
}

void brute() {
    while (true) {
        vector<ii> full_game;

        int a = 0, b = 0;

        full_game.push_back({a,b});
        while (a < 11 && b < 11) {
            if ((rand()%2)) {
                a += 1;
            } else {
                b += 1;
            }
            if ((a+b)%4 == 1 || (a+b)%4 == 2)full_game.push_back({a,b});
            else full_game.push_back({b,a});
        }

        int r = check(full_game.size(), full_game);
        if (r) {
            cout << r << endl;
            for (auto ii : full_game) {
                cout << ii[0] << " " << ii[1] << endl;
            }
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    int n;
    cin >> n;

    vector<string> a(n);
    for (auto& s : a)cin >> s;

    vector<ii> score;

    int px = 0, py = 0;
    for (int i = 0; i < n; ++i) {
        string s = a[i];
        int x = stoi(s.substr(0, s.find("-")));
        int y = stoi(s.substr(s.find("-")+1));
        score.push_back({x,y});

    }

    int r = check(n, score);
    if (!r)cout << "ok" << endl;
    else cout << "error " << r << endl;
}

