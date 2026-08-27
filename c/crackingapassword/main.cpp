#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int query(ll x) {
    cout << "? ";
    for (ll chunk = 0; chunk < 15; ++chunk) {
        int bite = (x >> (56 - chunk * 4)) & 0xF;
        cout << "0123456789ABCDEF"[bite];
    }
    cout << endl; cout.flush();
    string resp;
    cin >> resp >> resp;
    if (resp == "high!") return 1;
    else if (resp == "low!") return -1;
    return 0;
}

int main() {
    ll lo = 0;
    ll hi = 0xFFFFFFFFFFFFFFFLL;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        int r=  query(mid);

        if (r < 0) {
            lo = mid + 1;
        } else if (r > 0) {
            hi = mid - 1;
        } else break;
    }
}
