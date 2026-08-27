#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int mx = -200005;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x >= mx) {
            cout << x << " ";
            mx = x;
        }
    }
    cout << endl;
}
