#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
template<typename t, size_t N>
using ar = array<t,N>;
using ii = ar<ll,2>;
using vii = vector<ii>;
using ld = long double;

#define all(v) begin(v), end(v)

const int INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<ll>::max();

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (unsigned ll)rng() % B;
}
template<typename t>
istream& operator >> (istream& in, vector<t>& vec) {
    for (t& x : vec)in >> x;
    return in;
}

template<typename t>
ostream& operator << (ostream& out, vector<t>& vec) {
    int n = (int)vec.size();
    for (int i = 0; i < n; ++i) {
        out << vec[i];
        if (i < n - 1)out << " ";
    }
    return out;
}

template<typename t>
t min(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = min(ans, el);
    }
    return ans;
}

template<typename t>
t max(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = max(ans, el);
    }
    return ans;
}
const int mxN = 2e5+7;

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {

}
using vs = vector<string>;

ll score(string name, int location, size_t num_played) {
    if (name == "Shadow")return 6;
    if (name == "Gale")return 5;
    if (name == "Ranger")return 4;
    if (name == "Anvil")return 7;
    if (name == "Vexia")return 3;
    if (name == "Guardian")return 8;
    if (name == "Thunderheart" && num_played == 4)return 12;
    if (name == "Thunderheart")return 6;
    if (name == "Frostwhisper")return 2;
    if (name == "Voidclaw")return 3;
    if (name == "Ironwood")return 3;
    if (name == "Zenith" && location == 1)return 9;
    if (name == "Zenith")return 4;
    if (name == "Seraphina")return num_played;
    return 0;
}

int main() {
    setIO();
    pre();

    vector<vector<vs>> cards(3, vector<vs>(2, vs()));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            int k;
            cin >> k;

            cards[i][j] = vs(k);
            cin >> cards[i][j];
        }
    }

    vector<vll> scoret(3, vll(2, 0));
    vll scores(2, 0);
    vll nwin(2,0);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (string s : cards[i][j]) {
                scoret[i][j] += score(s, i, cards[i][j].size());
            }
            scores[j] += scoret[i][j];
        }

        if (scoret[i][0] > scoret[i][1])++nwin[0];
        if (scoret[i][0] < scoret[i][1])++nwin[1];
    }

    if (nwin[0] > nwin[1]) {
        cout << "Player 1" << endl;
        return 0;
    }
    if (nwin[0] < nwin[1]) {
        cout << "Player 2" << endl;
        return 0;
    }

    if (scores[0] > scores[1]) {
        cout << "Player 1" << endl;
        return 0;
    }
    if (scores[0] < scores[1]) {
        cout << "Player 2" << endl;
        return 0;
    }

    cout << "Tie" << endl;

    return 0;
}

