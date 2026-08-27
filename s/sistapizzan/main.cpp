#include <iostream>
#include <numeric>
#include <vector>
#include <array>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;

using state = array<ll, 3>;

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x : a)cin >> x;

    state st;

    set<state> win;
    win.insert({1,1,0});
    win.insert({2,0,0});
    win.insert({2,1,0});
    win.insert({2,1,1});
    win.insert({2,2,1});
    win.insert({2,2,2});

    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0)a[i] = 2;
        else a[i] = 1;
    }

    sort(rbegin(a), rend(a));

    for (int i = 0; i < 3; ++i)st[i] = 0;
    for (int i = 0; i < n; ++i)st[i] = a[i];


    cout << (win.count(st) ? "Ja" : "Nej") << endl;
}
