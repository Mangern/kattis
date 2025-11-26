#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ask(ll c, ll r) {
    cout << "? " << c << " " << r << endl;
    ll h;
    cin >> h;
    return h;
}

void answer(ll c, ll r) {
    cout << "! " << c << " " << r << endl;
    exit(0);
}

int main() {
    ll n;
    cin >> n;
    ll start = ask(n, 1);

    if (start == n) {
        answer(n, 1);
    }

    ll y = ask(n-start, 1);
    answer(start, y);
}
