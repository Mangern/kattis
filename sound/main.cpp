#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

const int mxN = 1e6+7;

ll n, m, c;
ll a[mxN];

int main() {
    scanf("%lld%lld%lld", &n, &m, &c);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }

    // {val,idx}
    // front: extremum
    deque<ii> minq, maxq;
    bool found = 0;

    for (int i = 0; i < n; ++i) {
        while (minq.size() && minq.back()[0] >= a[i])
            minq.pop_back();

        while (maxq.size() && maxq.back()[0] <= a[i])
            maxq.pop_back();

        minq.push_back({a[i], i});
        maxq.push_back({a[i], i});

        while (minq.size() && minq.front()[1] <= i - m)
            minq.pop_front();

        while (maxq.size() && maxq.front()[1] <= i - m)
            maxq.pop_front();

        if (i + 1 >= m) {
            if (maxq.front()[0] - minq.front()[0] <= c) {
                found = 1;
                printf("%lld\n", i + 2 - m);
            }
        }
    }

    if (!found) {
        printf("NONE\n");
    }
}
