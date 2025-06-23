#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// returns boolean value of g > j
bool guess(ll g) {
    cout << g << endl;
    string resp;
    cin >> resp;

    if (resp == "correct") {
        exit(0);
    }

    return resp == "lower";
}

int main() {
    ll b;
    cin >> b;

    ll lo = 1;
    ll hi = 1e9;

    for (int i = 0; i < 27 && lo < hi; ++i) {
        ll mid = (lo + hi + 1) / 2;

        if (guess(mid)) {
            hi = mid - 1;
        } else {
            lo = mid;
        }
    }

    for (ll i = lo; i <= hi; ++i) {
        guess(i);
    }
}
