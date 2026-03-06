#include <bits/stdc++.h>
using namespace std;

int main() {
    string inp;
    cin >> inp;

    list<char> ans;

    list<char>::iterator cursor = ans.end();

    for (char c: inp) {
        if (c == 'L') {
            --cursor;
        } else if (c == 'R') {
            ++cursor;
        } else if (c == 'B') {
            --cursor;
            cursor = ans.erase(cursor);
        } else {
            ans.insert(cursor, c);
        }
    }
    for (char c : ans)cout << c;
    cout << endl;
}
