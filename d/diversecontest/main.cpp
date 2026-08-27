#include <bits/stdc++.h>
using namespace std;
#define FORMASK(i, mask) for (int _x = (mask), i; i = 31-__builtin_clz(_x&(-_x)), _x; _x -= (_x&-_x)) 

int main() {
    int n, k;
    cin >> n >> k;

    map<string,int> id;
    int t = 0;
    vector<vector<int>> has(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            string s;
            cin >> s;
            if (!id.count(s))id[s] = t++;
            has[i].push_back(id[s]);
        }
    }
    int ans=0;
    for (int mask = 0; mask < (1<<n); ++mask) if (__builtin_popcount(mask) == k) {
        vector<int> cnt(t,0);

        bool poss=1;
        FORMASK(i, mask) {
            for (int t : has[i]) if (2*++cnt[t] > k) poss=0;
        }
        ans += poss;
    }
    cout << ans << endl;
}
