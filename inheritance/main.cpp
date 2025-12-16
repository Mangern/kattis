#include <bits/stdc++.h>
#include <iterator>
using namespace std;
using ll = long long;

int main() {
    ll p;
    cin >> p;


    vector<ll> nums;

    queue<ll> q;
    q.push(0);

    while (q.size()) {
        ll u = q.front();
        q.pop();
        if (u>0)nums.push_back(u);

        if (u * 10 + 2 <= p)q.push(u * 10 + 2);
        if (u * 10 + 4 <= p)q.push(u * 10 + 4);
    }

    sort(begin(nums), end(nums));

    for (auto d : nums) if (p % d == 0)cout << d << "\n";
}
