#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll q;
    cin >> q;
    vector<ll> top;

    ll cum_delta = 0;

    auto collapse = [&]() {
        for (auto &el : top)el += cum_delta;
        cum_delta = 0;
    };

    while (q-->0) {
        ll t, x;
        cin >> t >> x;

        if (t == 1) {
            collapse();
            top.push_back(x);
            for (int ptr = (int)top.size()-1; ptr > 0; --ptr) {
                if (top[ptr] < top[ptr-1]) {
                    swap(top[ptr], top[ptr-1]);
                } else break;
            }
            if (top.size() > 10)top.pop_back();
        } else if (t == 2) {
            cum_delta += x;
        } else {
            collapse();
            cout << top[x-1] << '\n';
        }
    }
}
