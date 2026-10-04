#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<ll, ll>;
constexpr ll p1 = 970592641, base=9999907; 
constexpr ll p2 = 971123723;

constexpr int maxn =1e6+5;

ll ex[maxn];
ll ex2[maxn];

struct Hash {
    ll operator()(const ii& p) const {
        return (p.first << 31) ^ p.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ex[0] = 1;
    for (int i = 1; i < maxn; i++) ex[i] = (base * ex[i-1]) % p1;

    ex2[0] = 1;
    for (int i = 1; i < maxn; i++) ex2[i] = (base * ex2[i-1]) % p2;

    int n, k;
    cin >> k >> n;

    unordered_map<ii, int, Hash> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) v[i] = i+1;
    ii hash  = {0,0};

    for (ll i = 0; i < n; i++)
    {
        hash.first += v[i] * ex[i];
        hash.first %= p1;
        hash.second += v[i] * ex[i];
        hash.second %= p2;
    }

    ll output = 0;
    
    m[hash] = 1;

    ll a, b;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;

        hash.first -= (v[a-1] * ex[a-1]) % p1;
        hash.first -= (v[b-1] * ex[b-1]) % p1;
        hash.second -= (v[a-1] * ex2[a-1]) % p2;
        hash.second -= (v[b-1] * ex2[b-1]) % p2;
        
        swap(v[a-1], v[b-1]);

        hash.first += (v[a-1] * ex[a-1]) % p1;
        hash.first += (v[b-1] * ex[b-1]) % p1;
        hash.second += (v[a-1] * ex2[a-1]) % p2;
        hash.second += (v[b-1] * ex2[b-1]) % p2;

        hash.first = ((hash.first %  p1) + p1) % p1;
        hash.second = ((hash.second %  p2) + p2) % p2;

        output += m[hash];

        m[hash]++;
    }

    cout << output << "\n";
}
