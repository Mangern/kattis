#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, p;
    cin >> p >> t;

    string s;
    cin >> s;

    int n = s.length();

    vector<int> que;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'I') {
            que.push_back(i);
        }
    }

    int tim = p;

    while (tim < t) {
        vector<int> nque;

        for (int i : que) {
            if (i - 1 >= 0 && s[i-1] == 'H') {
                s[i-1] = 'I';
                nque.push_back(i-1);
            }
            if (i + 1 < n && s[i+1] == 'H') {
                s[i+1] = 'I';
                nque.push_back(i+1);
            }
        }
        swap(que, nque);
        tim += p;
    }

    if (s.find('H') != string::npos) {
        cout << "CURED" << endl;
    } else {
        cout << "ALL INFECTED" << endl;
    }
}
