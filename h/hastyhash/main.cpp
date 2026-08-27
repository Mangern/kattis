#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD=1LL<<32;

int main() {
    ll x;
    cin >> x;

    vector<string> ans;

    for (char c1 = 'A'; c1 <= 'Z'; ++c1)
    for (char c2 = 'A'; c2 <= 'Z'; ++c2)
    for (char c3 = 'A'; c3 <= 'Z'; ++c3)
    for (char c4 = 'A'; c4 <= 'Z'; ++c4)
    for (char c5 = 'A'; c5 <= 'Z'; ++c5) {
        ll hash = 2'166'136'261;
        ll prime = 16'777'619;
        hash ^= c1;
        hash *= prime;
        hash &= (MOD-1);
        hash ^= c2;
        hash *= prime;
        hash &= (MOD-1);
        hash ^= c3;
        hash *= prime;
        hash &= (MOD-1);
        hash ^= c4;
        hash *= prime;
        hash &= (MOD-1);
        hash ^= c5;
        hash *= prime;
        hash &= (MOD-1);
        if (hash == x) {
            ans.push_back(string{c1,c2,c3,c4,c5});
        }
    }


    if (ans.empty())cout << "impossible" << endl;
    else {
        for (auto s : ans) cout << s << endl;
    }
}
