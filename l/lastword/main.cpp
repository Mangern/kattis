#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    string_view sv{s};
    while (q-->0) {
        int i, l;
        cin >> i >> l;
        sv = sv.substr(i,l);
    }
    cout << sv << endl;
}
