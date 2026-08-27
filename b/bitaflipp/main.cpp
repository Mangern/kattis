#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5+5;

int n0[mxN];
int n1[mxN];
int dif[mxN];
int mxr[mxN];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x) {
            --dif[i];
            ++n1[i];
        }
        else {
            ++n0[i];
            ++dif[i];
        }
        if(i>0) {
            dif[i]+=dif[i-1];
            n1[i] += n1[i-1];
            n0[i] += n0[i-1];
        }
    }
    mxr[n-1] = n - 1;

    for (int i = n - 2; i >= 0; --i) {
        if (dif[i]>dif[mxr[i+1]])mxr[i] = i;
        else mxr[i] = mxr[i+1];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int j = mxr[i];

        int tot1 = ((i==0)?0:n1[i-1])
                 + (n1[n-1]-n1[j])
                 + (n0[j]-(i==0?0:n0[i-1]));
        ans=max(ans,tot1);
    }
    cout << ans << endl;
}
