#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> id(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x, --x;
        id[x] = i;
    }

    int m;
    cin >> m;

    while (m-->0) {
        vector<int> arr(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            arr[i] = id[arr[i]-1];
            for (int j = 0; j < i; ++j) {
                ans += arr[j] > arr[i];
            }
        }
        cout << ans << endl;
    }
}
