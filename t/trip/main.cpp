#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    for(;;) {
        ll n;
        cin >> n;

        if (!n)break;

        vector<ll> a;
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;

            s[s.length() - 3] = s[s.length() - 2];
            s[s.length() - 2] = s[s.length() - 1];
            s.pop_back();

            a.push_back(stoull(s) + 1);
            sum += a.back();
        }

        ll ans = 0;
        ll goal = sum / n;
        ll cnt = 0;
        for (auto x : a) {
            if (x > goal) {
                ans += x - goal;
                ++cnt;
            }
        }

        if (cnt >= sum % n)ans -= (sum % n);
        else ans -= cnt;

        cout << "$" << (ans / 100) << "." << setw(2) << setfill('0') << (ans % 100) << endl;
    }
}
