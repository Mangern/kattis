#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const int mxN = 3e6+7;

int npf[mxN];
ll save[mxN];
vll p;

ll num_div(ll n) {
    ll ans = 1;
    for (int i = 0; i < p.size() && p[i] * p[i] <= n; ++i) {
        int pw = 0;
        while (n % p[i] == 0) {
            n /= p[i];
            ++pw;
        }
        ans *= (pw+1);
    }
    if (n != 1) ans *= 2;
    return ans;
}

void sieve() {
    for (ll i = 2; i < mxN; ++i) if (!npf[i]) {
        p.push_back(i);
        for (ll j = i; j < mxN; j += i)++npf[j];
    }
}

int main() {
    sieve();
    ll q;
    scanf("%lld", &q);
    
    ll i;
    while (q --> 0) {
        scanf("%lld", &i);
        if (save[i])printf("%lld\n",save[i]);
        else printf("%lld\n", save[i] = (num_div(i) - npf[i]));
    }
}
