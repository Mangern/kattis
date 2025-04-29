#include <bits/stdc++.h>
using namespace std;
using ll = long long;

enum class result {
    WIN,
    TIE,
    LOSE
};

ll n;

vector<ll> pfs;

void test() {
    cin >> n;
    string start;
    cin >> start;
    string other;
    if (start[0] == 'A')other = "Bob";
    else other = "Alice";

    pfs.clear();

    ll x = n;
    for (ll i = 2; i * i <= n && pfs.size() < 2; ++i) {
        if (x % i == 0) {
            pfs.push_back(i);
            while (x % i == 0)x /= i;
        }
    }
    if (x>1)pfs.push_back(x);

    if (pfs.size() > 2) {
        printf("%s\n", "tie");
        return;
    }

    if (pfs.size() == 1) {
        int cnt = 0;
        while (n % pfs[0] == 0) {
            ++cnt;
            n /= pfs[0];
        }
        if (cnt & 1)printf("%s\n", start.c_str());
        else printf("%s\n", other.c_str());
        return;
    } else {
        int cnt0 = 0, cnt1 = 0;
        while (n % pfs[0] == 0) {
            ++cnt0;
            n /= pfs[0];
        }
        while (n % pfs[1] == 0) {
            ++cnt1;
            n /= pfs[1];
        }
        if (cnt0 == cnt1) printf("%s\n", other.c_str());
        else if (abs(cnt0-cnt1)==1)printf("%s\n", start.c_str());
        else printf("%s\n", "tie");
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t-->0)test();
}
