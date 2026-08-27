#pragma GCC optimize("O3", "unroll-loops")
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int mxN = 1e6+6;

constexpr int BITS = 10;
constexpr int K = (1<<BITS);

int _arr1[mxN];
int _arr2[mxN];
int cnt[K];

inline void solve() {
    int n;
    scanf("%d", &n);
    ll a, b, c, x, y;
    scanf("%lld%lld%lld%lld%lld", &a,&b,&c,&x,&y);

    int* arr = _arr1;
    int* barr = _arr2;

    arr[0] = a;

    b %= c;
    a %= c;

    ++cnt[arr[0]&(K-1)];
    for (int i = 1; i < n; ++i) {
        arr[i] = (arr[i-1] * b + a) % c;
        ++cnt[arr[i]&(K-1)];
    }

    for (int k = 0;; ) {
        int ptr = 0;

        for (int i = 1; i < K; ++i) {
            cnt[i] += cnt[i-1];
        }
        for (int i = n - 1; i >= 0; --i) {
            barr[--cnt[(arr[i]>>k)&(K-1)]] = arr[i];
        }
        swap(arr, barr);

        bool eq = (cnt[1] == cnt[K-1]);
        memset(cnt, 0, sizeof cnt);
        k += BITS;
        if (k>=30 || eq)break;

        for (int i = 0; i < n; ++i) {
            ++cnt[(arr[i]>>k)&(K-1)];
        }
    }
    ll v = 0;
    for (int i = 0; i < n; ++i) {
        v = (v * x + arr[i]) % y;
    }
    printf("%lld\n", v);
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc-->0)solve();
}
