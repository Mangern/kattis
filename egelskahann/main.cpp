#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e6+6;

int nxt[mxN];
int prv[mxN];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        nxt[i] = j;
        prv[j] = i;
    }

    int ptr = 0;
    bool turn = 0;
    int rem = n;

    while (rem>1) {
        if (turn) {
            // remove ptr
            nxt[prv[ptr]] = nxt[ptr];
            prv[nxt[ptr]] = prv[ptr];
            --rem;
        }
        ptr = nxt[ptr];
        turn = !turn;
    }

    cout << ptr+1 << endl;
}
