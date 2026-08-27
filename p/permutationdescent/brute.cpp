#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)a[i] = i;

    vector<int> has(n,0);
    do {
        int cnt = 0;
        for (int i = 0; i < n - 1; ++i)if(a[i] > a[i+1])++cnt;
        ++has[cnt];
    } while (next_permutation(begin(a),end(a)));

    for (auto x : has)cout << x << " ";
    cout << endl;
}
