#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

const int mxN = 5e5+4;

int st[mxN<<2];

int n;

void update(int p, int l, int r, int idx, int val) {
    if (idx < l || idx > r)return;
    if (l == r) {
        st[p] = val;
        return;
    }

    int mid = (l+r)>>1;
    update(p<<1,l,mid,idx,val);
    update(p<<1|1,mid+1,r,idx,val);
    st[p] = max(st[p<<1],st[p<<1|1]);
}

void update(int i, int v) {
    update(1,0,n-1,i,v);
}

int query(int p, int l, int r, int i, int j) {
    if (j < l || i > r)return -1;
    if (i <= l && r <= j)return st[p];
    int mid = (l+r)>>1;
    return max(query(p<<1,l,mid,i,j), query(p<<1|1,mid+1,r,i,j));
}

int query(int i, int j) {
    return query(1,0,n-1,i,j);
}

int main() {
    cin >> n;

    vector<int> b(n);
    for (auto& x : b)cin >> x, --x;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int m = query(0,b[i]);
        update(b[i],m+1);
        ans = max(ans,m+1);
    }
    cout << ans << endl;
}
