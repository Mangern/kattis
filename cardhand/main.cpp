#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct card {
    int  rank;
    char suit;
};

card fromstr(const string& s) {
    card c;
    if ('2' <= s[0] && s[0] <= '9') {
        c.rank = s[0] - '0';
    } else if (s[0] == 'T')c.rank = 10;
    else if (s[0] == 'J')c.rank = 11;
    else if (s[0] == 'Q')c.rank = 12;
    else if (s[0] == 'K')c.rank = 13;
    else if (s[0] == 'A')c.rank = 14;
    c.suit = s[1];
    return c;
}

int main() {
    int n;
    cin >> n;

    vector<card> cards;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cards.push_back(fromstr(s));
    }

    string suits = "cdhs";
    vector<card> orig = cards;

    int ans = 10000;
    do {
        for (int mask = 0; mask < 16; ++mask) {
            sort(begin(cards), end(cards), [&](const card& ca, const card& cb) {
                int sidxa = suits.find(ca.suit);
                int sidxb = suits.find(cb.suit);

                if (sidxa != sidxb) return sidxa < sidxb;

                int asc = (mask >> sidxa)&1;
                if (asc) return ca.rank < cb.rank;
                return ca.rank > cb.rank;
            });

            vector<int> dp(n, 1);
            vector<int> order(n);

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (orig[i].suit == cards[j].suit && orig[i].rank == cards[j].rank) {
                        order[i] = j;
                        break;
                    }
                }
            }

            int lis = 1;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (order[j] < order[i]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                        lis = max(lis, dp[i]);
                    }
                }
            }

            ans = min(ans, n - lis);
        }
    } while (next_permutation(begin(suits), end(suits)));

    cout << ans << endl;
}

// 0 3 1 2 4
// 0 1 2 3 4
//
// 1 2 3 0
