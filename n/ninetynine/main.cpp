#include <bits/stdc++.h>
using namespace std;

bool win[100];
int play[100];

int main() {
    win[99] = 0;
    win[98] = 1;
    play[98] = 1;
    win[97] = 1;
    play[97] = 2;

    for (int i = 96; i >= 0; --i) {
        // win[i] = true if win[i+1] or win[i+2] is false
        // if win is true, play is 1 or 2
        if (!win[i+1]) {
            win[i] = true;
            play[i] = 1;
        } else if (!win[i+2]) {
            win[i] = true;
            play[i] = 2;
        } else {
            play[i] = i % 2 + 1; // hope
        }
    }

    //for (int i = 0; i < 99; ++i) {
    //    cout << i << ": " << win[i] << " " << play[i] << endl;
    //}

    int cur = 0;

    for (;;) {
        cur += play[cur];
        cout << cur << endl;
        if (cur == 99) {
            break;
        }

        int x;
        cin >> x;
        assert(x != 99);
        cur = x;
    }
}
