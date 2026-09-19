#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-->0) {
        cout << "3 1 3 6" << endl;

        for (;;) {
            string cmd;
            cin >> cmd;

            if (cmd == "GAME") break;

            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;

            r1 = 6 - r1;
            c1 = 7 - c1;
            r2 = 6 - r2;
            c2 = 7 - c2;

            if (r2 < r1)swap(r1, r2);
            if (c2 < c1)swap(c1, c2);

            cout << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
        }
    }
}
