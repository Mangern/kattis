#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n+1,-1);
    vector<int> a(n-1);
    vector<int> freq(n+1,0);
    vector<int> chain;
    for (auto &x : a) {
        cin >> x;
        if (++freq[x] == 1)chain.push_back(x);
    }
    sort(begin(chain), end(chain));
    for (int i = 1; i < chain.size(); ++i) {
        p[chain[i]] = chain[i-1];
        --freq[chain[i-1]];
    }

    int ptr = 1;
    for (int i = 2; i <= n; ++i) {
        while (ptr <= n && !freq[ptr])++ptr;
        if (p[i] == -1) {
            p[i] = ptr;
            --freq[ptr];
        }
    }
    for (int i = 2; i <= n; ++i)cout << p[i] << ' ';
    cout << endl;
}
