#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n, 0);

    int k;
    cin >> k;
    a[k-1] = 1;

    int q;
    cin >> q;
    while (q-->0){ 
        int u, v; 
        cin >> u >> v, --u, --v;
        swap(a[u], a[v]);
    }

    cout << max_element(begin(a), end(a)) - begin(a) + 1 << endl;
}
