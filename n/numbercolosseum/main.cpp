#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    deque<ll> neg, pos;

    ll n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;

        if (x < 0) {
            neg.push_back(x);
        } else {
            pos.push_back(x);
        }

        while (neg.size() && pos.size()) {
            if (-neg.back() > pos.back()) {
                neg.back() += pos.back();
                pos.pop_back();
            } else if (-neg.back() < pos.back()) {
                pos.back() += neg.back();
                neg.pop_back();
            } else {
                pos.pop_back();
                neg.pop_back();
            }
        }
    }

    if (neg.empty() && pos.empty()) {
        cout << "Tie!" << endl;
    } else if (neg.size()) {
        cout << "Negatives win!" << endl;
        for (auto x : neg)cout << x << ' ';
        cout << endl;
    } else {
        cout << "Positives win!" << endl;
        for (auto x : pos) cout << x << ' ';
        cout << endl;
    }
}
