#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long d;
    cin >> d;


    long long n = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'B')n |= (1<<i);
    }

    n += d;

    for (int i = 0; i < s.length(); ++i) {
        cout << char('A'+((n>>i)&1));
    }
    cout << endl;
}
