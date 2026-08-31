#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;

int used = 0;
int query(int l1, int r1, int l2, int r2) {
    cout << "Q " << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
    ++used;
    int w1, w2;
    cin >> w1 >> w2;
    return (w1 << 1) | w2;
}

int answer(int t) {
    cout << "A " << t << endl;
    exit(0);
}

// 1, 2, 3, 4, 5, 6, 7, 8

void solve(ll l, ll r) {
    l = max(l, 1LL);
    r = min(r, n);
    //if (used == 16) {
    //    answer(l);
    //}
    int len = r - l;
    if (len == 0) {
        answer(l);
    }
    if (len <= 2) {
        int w = query(l, l, r, r);
        if (w == 2)answer(l);
        else if (w == 0)answer(l+1);
        else answer(r);
    }
    if (len == 3) {
        int w = query(l, l+1, l+1, r-1);
        if (w == 2)answer(l);
        if (w == 3)answer(l+1);
        if (w == 1)answer(r-1);
        answer(r);
    }

    ll m2 = (l+r+1)/2;
    ll m1 = (l+m2+1)/2;
    ll m3 = (r+m2)/2;

    int w = query(l, m2, m1, m3);
    switch(w) {
        case 0:
            solve(m3,r+1);
            break;
        case 1:
            solve(m2, m3+1);
            break;
        case 2:
            solve(l-1,m1);
            break;
        case 3:
            solve(m1-1,  m2+1);
            break;
    }
}

int main() {
    cin >> n;

    solve(1, n);
}
