#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        ll x;
        cin >> x;

        ll mul = 1;

        deque<ll> lft, rgt;

        while (x) {
            ll r = x % 3;
            if (r == 0) {
                mul *= 3;
                x /= 3;
                continue;
            } else if (r == 1) {
                rgt.push_front(mul);
                mul *= 3;
                x /= 3;
                continue;
            } else if (r == 2) {
                lft.push_front(mul);
                mul *= 3;
                x += 1;
                x /= 3;
                continue;
            }
        }
        cout << "left pan:";
        for (auto l : lft)cout << " " << l;
        cout << endl;

        cout << "right pan:";
        for (auto l : rgt)cout << " " << l;
        cout << endl;
        cout << endl;
    }
}
