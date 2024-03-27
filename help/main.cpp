#include <bits/stdc++.h>
using namespace std;
using ll =long long;

void testcase(int n) {
    vector<ll> a(n);
    for (auto& x : a)cin >> x;
    sort(begin(a), end(a));

    ll mx = a.back();
    a.pop_back();
    --n;


    ll close = a[0];
    int closei = 0;

    for (int i = 0 ;i < n; ++i) {
        ll x = a[i];
        if (abs(x - (mx >> 1)) < abs(close - (mx >> 1))) {
            close = x;
            closei = i;
        }
    }

    vector<ll> ans;

    for (int i = 0; i < n; ++i) if (i != closei)ans.push_back(a[i]);

    ans.push_back(mx);
    ans.push_back(close);

    reverse(begin(ans), end(ans));

    for (int i = 0; i < n+1; ++i) {
        cout << ans[i] << "-" << "AB"[i&1] << " \n"[i == n];
    }
}

int main() {
    for (;;) {
        int n;
        cin >> n;
        if (!n)break;
        testcase(n);
    }
}
