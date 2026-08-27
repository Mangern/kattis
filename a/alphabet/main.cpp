#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    vector<int> lis(n, 1);

    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[j] > s[i]) {
                lis[i] = max(lis[i], 1 + lis[j]);
            }
        }
    }
    cout << 26 - *max_element(begin(lis), end(lis)) << endl;
}
