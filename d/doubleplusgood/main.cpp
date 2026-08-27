#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll merge(ll a, ll b) {
    ll d = b;
    while (d>0) {
        d /= 10;
        a *= 10;
    }
    return a + b;
}

int main() {
    string s;
    cin >> s;

    unordered_set<ll> res;

    vector<ll> nums;

    int nplus = 0;

    for (int i = 0; i < s.length(); ) {
        if (s[i] == '+') {
            ++nplus;
            ++i;
            continue;
        }

        int j;
        for (j = i; j < s.length(); ++j) {
            if (s[j] == '+') break;
        }

        nums.push_back(stoll(s.substr(i, j - i)));
        i = j;
    }

    assert(nums.size() == nplus+1);

    vector<ll> bnums;
    for (int mask = 0; mask < (1<<(nplus)); ++mask) {
        bnums.clear();
        bnums.push_back(nums[0]);
        for (int i = 0; i < nplus; ++i) {
            if ((mask >> i) & 1) {
                // merge with prev
                ll top = bnums.back();
                bnums.pop_back();
                bnums.push_back(merge(top, nums[i+1]));
            } else {
                bnums.push_back(nums[i+1]);
            }
        }
        ll cur = accumulate(begin(bnums), end(bnums), 0LL);

        res.insert(cur);
    }
    cout << res.size() << endl;
}
