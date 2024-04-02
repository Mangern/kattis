#include <bits/stdc++.h>
using namespace std;
const int mxN = 200005;

int n, q;
pair<int,string> a[mxN];
pair<int,int> query[mxN];

string ans[mxN];

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i].second >> a[i].first;
    }
    cin >> q;

    for (int i = 0; i < q; ++i) {
        cin >> query[i].first;
        query[i].second = i;
    }

    sort(a, a+n);
    sort(query, query+q);

    int i = 0;

    for (int j = 0; j < q; ++j) {
        while (i < n - 1 && a[i+1].first <= query[j].first) {
            ++i;
        }
        if (a[i].first > query[j].first) {
            ans[query[j].second] = ":(";
        } else {
            ans[query[j].second] = a[i].second;
        }
    }

    for (int j = 0; j < q; ++j) {
        cout << ans[j] << endl;
    }
}
