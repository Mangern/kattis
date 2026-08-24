#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    using tup = array<ll, 3>;
    priority_queue<tup, vector<tup>, greater<tup>> pq;
    for (int i = 0; i < n; ++i) {
        ll t,d, c;
        cin >> t >> d >> c;
        pq.push({t+d,d,c});
    }
    ll friend_free = 0;
    while (pq.size()) {
        auto [t,d,c] = pq.top();
        pq.pop();
        t-=d;
        friend_free = max(friend_free + c, t + d + c);
    }
    cout << friend_free << endl;
}
