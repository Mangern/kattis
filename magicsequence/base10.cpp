#include <cstring>
#pragma GCC optimize("O3", "unroll-loops")
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int mxN = 1e6+6;

int _arr1[mxN];
int _arr2[mxN];
int cnt[10];

inline int digit(int n, int& k) {
    for (int i = 0; i < k; ++i)n /= 10;
    return n % 10;
}

inline void solve() {
    int n;
    cin >> n;
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int* arr = _arr1;
    int* barr = _arr2;

    arr[0] = a;

    b %= c;
    a %= c;

    for (int i = 1; i < n; ++i) {
        arr[i] = (arr[i-1] * b + a) % c;
    }
    for (int k = 0; k < 10; k++) {
        int ptr = 0;
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; ++i) {
            ++cnt[digit(arr[i], k)];
        }
        cnt[1] += cnt[0];
        cnt[2] += cnt[1];
        cnt[3] += cnt[2];
        cnt[4] += cnt[3];
        cnt[5] += cnt[4];
        cnt[6] += cnt[5];
        cnt[7] += cnt[6];
        cnt[8] += cnt[7];
        cnt[9] += cnt[8];

        for (int i = n - 1; i >= 0; --i) {
            barr[(cnt[digit(arr[i], k)]--) -1] = arr[i];
        }
        swap(arr, barr);
    }
    ll v = 0;
    for (int i = 0; i < n; ++i) {
        v = (v * x + arr[i]) % y;
    }
    cout << v << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;
    cin >> tc;
    while (tc-->0)solve();
}
