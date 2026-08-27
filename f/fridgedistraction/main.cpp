#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s(n,'a');
    iota(begin(s), end(s), 'a');

    string ans;
    while (k > 0) {
        int idx = min(k - 1, n - 1);
        char c = s[idx];
        ans.push_back(c);
        s.erase(idx);
        s.insert(s.begin(), c);
        k -= idx+1;
    }
    cout << ans.length() << endl;
    for (char c : ans)cout << c << " ";
    cout << endl;
}
