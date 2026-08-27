#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e4+5;
int main() {
    string line;
    while (getline(cin, line)) {
        ll n = stoll(line.substr(2,line.length()));

        ll cnt=0;
        for (ll x = 2 * n; x > n; --x) {
            if ((n * x) % (x - n) == 0) {
                ++cnt;
            }
        }
        cout << cnt << endl;
    }
}
