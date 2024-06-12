#include <iostream>
#include <list>
#include <string>

using namespace std;

void solve() {
    string inp;
    getline(cin, inp);

    list<char> res;
    auto it = res.begin();

    for (char c : inp) {
        if (c == '[') {
            it = res.begin();
        } else if (c == ']') {
            it = res.end();
        } else if (c == '<') {
            if (it == res.begin())continue;
            --it;
            it = res.erase(it);
        } else {
            it = res.insert(it, c);
            ++it;
        }
    }

    if (res.empty())return;

    for (char c : res)cout << c;
    cout << endl;
}

int main() {
    int T = 1;
    while (T-->0)solve();
}
