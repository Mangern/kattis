#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

const int mxN = 5e5+2;

ll n, m, q;

int k[mxN];

int dist(ll x, ll y) {
    return min(((x-y)%(2*n)+(2*n))%(2*n), ((y-x)%(2*n)+(2*n))%(2*n));
}

int rgt(int i) {
    if (i < k[0] || i >= k[m-1]+n)return k[m-1]+n;
    if (i >= k[m-1] && i < k[0]+n)return k[m-1];
    int ssp = 0;
    if (i >= k[0] + n)ssp = n;
    int lo = 0;
    int hi = m;
    while (lo + 1 < hi) {
        int mid = (lo+hi)/2;
        if (k[mid]+ssp > i)hi = mid;
        else lo = mid;
    }
    return k[lo]+ssp;
}

int lft(int i) {
    if (i <= k[0] || i > k[m-1]+n)return k[0];
    if (i > k[m-1] && i <= k[0]+n)return k[0]+n;
    int ssp = 0;
    if (i >= k[0] + n)ssp = n;
    int lo = -1;
    int hi = m - 1;

    while (lo + 1 < hi) {
        int mid = (lo+hi+1)/2;
        if (k[mid]+ssp < i)lo = mid;
        else hi = mid;
    }

    return k[hi]+ssp;
}


int main() {
    //k = new int[mxN];
    scanf("%lld%lld%lld", &n, &m, &q);
    for (int i = 0; i < m; ++i) {
        scanf("%d", k+i);
    }
    while (q-->0) {
        int x, y; 
        cin >> x >> y;
        if (x>y)swap(x,y);
        int ans = dist(x,y);
        int r = rgt(x);
        int rn;
        if (r >= n)rn = r - n;
        else rn = r + n;
        ans = min(ans, dist(x,r)+1+dist(rn,y));
        int l = lft(x);
        int ln;
        if (l >= n)ln = l - n;
        else ln = l + n;
        ans = min(ans, dist(x,l)+1+dist(ln,y));
        printf("%d\n", ans);
    }
}
