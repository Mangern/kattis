#include <iostream>

using namespace std;

const int mxN = 1e6+6;

int n;
int a[mxN];
int cnt[mxN];

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!cnt[a[i]+1]) {
            ++ans;
        } else {
            --cnt[a[i]+1];
        }
        ++cnt[a[i]];
    }

    cout << ans << endl;

}
