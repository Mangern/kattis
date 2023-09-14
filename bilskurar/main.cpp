#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll merge(vector<int>& a, int p, int q, int r) {
    vector<int> lft(begin(a)+p, begin(a)+q+1);
    vector<int> rgt(begin(a)+q+1, begin(a)+r+1);

    int lsz = lft.size();
    int rsz = rgt.size();

    int i = 0;
    int j = 0;
    int l = p;
    ll cnt = 0;
    while (i < lsz || j < rsz) {
        if (j == rsz) {
            a[p++] = lft[i++];
        } else if (i == lsz) {
            a[p++] = rgt[j++];
        } else if (lft[i] < rgt[j]) {
            a[p++] = lft[i++];
        } else {
            a[p++] = rgt[j++];
            cnt += (q+1) - (l+i);
        }
    }
    return cnt;
}

ll merge_sort(vector<int>& a, int p, int r) {
    if (p >= r)return 0;
    ll cnt = 0;
    int q = (p+r)/2;
    cnt += merge_sort(a, p, q);
    cnt += merge_sort(a, q+1, r);

    cnt += merge(a, p, q, r);
    return cnt;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto& x : a)cin >> x, --x;
    for (auto& x : b)cin >> x, --x;

    vector<int> idx(n);
    for (int i = 0; i < n; ++i)idx[a[i]] = i;

    for (int i = 0; i < n; ++i) {
        b[i] = idx[b[i]];
    }

    cout << merge_sort(b, 0, n - 1) << endl;

    return 0;

}
