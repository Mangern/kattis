//#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using arr = array<ll, 2>;
using arrr = array<ll, 3>;

void er(vector<string> &deck, int idx) {
    int j = idx;
    for (int i = idx + 1; i < deck.size(); ++i) {
        deck[j++] = deck[i];
    }
    deck.pop_back();
}

void cascade(vector<string> &deck) {
    int rem4 = -1;
    int rem2 = -1;
    for (int i = 3; i < deck.size(); ++i) {
        if (deck[i-3][0] == deck[i][0]) {
            rem4 = i;
        }
        if (deck[i-3][1] == deck[i][1]) {
            rem2 = i;
        }
    }

    if (rem2 == -1 && rem4 == -1) return;

    if (rem4 != -1) {
        er(deck, rem4);
        er(deck, rem4 - 1);
        er(deck, rem4 - 2);
        er(deck, rem4 - 3);
    } else {
        er(deck, rem2);
        er(deck, rem2 - 3);
    }
    cascade(deck);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> deck;

    for (int i = 0; i < 52; ++i) {
        string c;
        cin >> c;

        deck.push_back(c);
        cascade(deck);
    }

    cout << deck.size();

    for (auto s : deck) {
        cout << " " << s;
    }
    cout << endl;
}
