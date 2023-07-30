#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string,int> pos;
    int n,q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        pos[s] = i;
    }

    while (q-->0) {
        string a,b;
        cin >> a >> b;
        int i = pos[a];
        int j = pos[b];

        cout << (abs(i-j)-1) << endl;
    }
}
