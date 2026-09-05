#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<unordered_map<int,int>> team_prefs(n);
    vector<vector<int>> player_prefs(k);

    vector<string> teams(n), players(k);

    unordered_map<string, int> team_id;
    unordered_map<string, int> player_id;

    for (int i = 0; i < n; ++i) {
        string team;
        cin >> team;
        int tid = i;
        team_id[team] = i;
        teams[i] = team;
        for (int j = 0; j < k; ++j) {
            string player;
            cin >> player;
            if (i == 0) {
                player_id[player] = j;
                players[j] = player;
            }
            team_prefs[i][player_id[player]] = j;
        }
    }
    for (int i = 0; i < k; ++i) {
        string player;
        cin >> player;
        int pid = player_id[player];
        for (int j = 0; j < n; ++j) {
            string team;
            cin >> team;
            player_prefs[pid].push_back(team_id[team]);
        }
    }

    // {pref_index, player}
    vector<set<ii>> ans(n);

    queue<int> q;
    for (int i = 0; i < k; ++i)q.push(i);

    while (q.size()) {
        int player = q.front();
        q.pop();


        bool ok = 0;
        for (int t : player_prefs[player]) {
            int my_pri = team_prefs[t][player];
            if (ans[t].size() < m) {
                ans[t].insert({my_pri, player});
                break;
            } else {
                auto worst = prev(ans[t].end());
                auto [worst_pri, worst_other] = *worst;
                if (my_pri < worst_pri) {
                    ans[t].erase(worst);
                    ans[t].insert({my_pri, player});
                    q.push(worst_other);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << teams[i];
        for (auto [_, p] : ans[i]) {
            cout << " " << players[p];
        }
        cout << endl;
    }
}
