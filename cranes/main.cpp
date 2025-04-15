#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FORMASK(i, mask) for (int _x = (mask), i; i = 31-__builtin_clz(_x&(-_x)), _x; _x -= (_x&-_x)) 


const int mxN = 15;

int n;
ll x[mxN];
ll y[mxN];
ll r[mxN];

void test() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> r[i];
    }

    ll ans = 0;
    for (int mask = 0; mask < (1<<n); ++mask) {
        bool good = 1;
        ll cur = 0;
        FORMASK(i, mask) {
            cur += r[i] * r[i];
            FORMASK(j, mask) if (j < i) {
                if (
                        (x[i] - x[j]) * (x[i] - x[j]) + 
                        (y[i] - y[j]) * (y[i] - y[j]) <=
                        (r[i] + r[j]) * (r[i] + r[j])) {
                    good = 0;
                    break;
                }
            }
            if (!good) break;
        }

        if (good) {
            ans = max(ans, cur);
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-->0)test();
    return 0;
}
