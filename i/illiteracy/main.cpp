#include <bits/stdc++.h>
using namespace std;

void rot(char& c) {
    ++c;
    if (c > 'F')c='A';
}

vector<string> neighbors(const string& state) {

    vector<string> ret;
    for (int x = 1; x <= 8; ++x) {
        string nxt = state;

        switch (state[x]) {
        case 'A':
            if (x > 1)rot(nxt[x-1]);
            if (x < 8)rot(nxt[x+1]);
            break;
        case 'B':
            if (1 < x && x < 8) nxt[x+1] = nxt[x-1];
            break;
        case 'C':
            rot(nxt[9-x]);
            break;
        case 'D':
            if (x <= 4) {
                for (int i = 1; i < x; ++i) {
                    rot(nxt[i]);
                }
            } else {
                for (int i = x + 1; i <= 8; ++i) {
                    rot(nxt[i]);
                }
            }
            break;
        case 'E':
            if (1 < x && x <= 4) {
                int y = x - 1;
                rot(nxt[x-y]);
                rot(nxt[x+y]);
            } else if (5 <= x && x < 8) {
                int y = 8 - x;
                rot(nxt[x-y]);
                rot(nxt[x+y]);
            }
            break;
        case 'F':
            if (x & 1) {
                rot(nxt[(x+9)/2]);
            } else {
                rot(nxt[x/2]);
            }
            break;
        }

        ret.push_back(nxt);
    }
    return ret;
}

int main() {
    string start;
    cin >> start;

    string goal;
    cin >> goal;

    start = "0"+start;
    goal = "0"+goal;

    unordered_map<string, int> dist;
    dist[start] = 0;

    queue<string> q;
    q.push(start);

    while (q.size()) {
        string state = q.front();
        q.pop();

        if (state == goal) break;

        for (auto nei : neighbors(state)) {
            if (!dist.count(nei)) {
                dist[nei] = dist[state] + 1;
                q.push(nei);
            }
        }
    }

    cout << dist[goal] << endl;
}
