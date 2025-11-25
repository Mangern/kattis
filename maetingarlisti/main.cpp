#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r, c;
    cin >> n >> r >> c;


    vector<vector<string>> rows(r);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            string s;
            cin >> s;
            rows[i].push_back(s);
        }
    }

    for (int i = 0; i < r; ++i) {
        vector<string> rw;

        for (int j = 0; j < c; ++j) {
            string s;
            cin >> s;
            rw.push_back(s);
        }

        if (rw == rows[i]) {
            cout << "left" << endl;
        } else {
            cout << "right" << endl;
        }
    }
}
