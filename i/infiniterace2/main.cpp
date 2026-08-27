#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    set<int> behind;

    int ans=0;
    while (q-->0) {
        int x;
        cin >> x;

        if (x > 0) {
            if (behind.count(x)) {
                ++ans;
                behind.clear();
                behind.insert(x);
            } else {
                behind.insert(x);
            }
        } else {
            x=-x;
            if (behind.count(x)) {
                behind.erase(x);
            }
        }
    }

    cout << ans << endl;
}
