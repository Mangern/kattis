#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (auto &x : c)cin >> x;

    sort(begin(c), end(c));
    do {
        bool good=1;
        for (int i = 1; i < n; ++i) {
            if (__gcd(c[i], c[i-1])==1) {
                good=0;
                break;
            }
        }
        if (good) {
            for (auto x : c)cout << x << " ";
            cout << endl;
            return 0;
        }
    } while (next_permutation(begin(c), end(c)));
    cout << "Neibb" << endl;
}
