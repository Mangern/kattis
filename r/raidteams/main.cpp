#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1e5+5;

char buf[20];

int n;
string name[mxN];
int skill[mxN][3];
bool vis[mxN];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        memset(buf, 0, sizeof buf);
        scanf("%s", buf);

        for (char* c = buf; *c; ++c) {
            name[i].push_back(*c);
        }
        scanf("%d%d%d", &skill[i][0], &skill[i][1], &skill[i][2]);
    }

    deque<int> s1(n), s2, s3;
    iota(begin(s1), end(s1), 0);
    s2 = s1;
    s3 = s1;

    sort(begin(s1), end(s1), [&](auto i, auto j) {
        if (skill[i][0] == skill[j][0]) {
            return name[i] < name[j];
        }
        return skill[i][0] > skill[j][0];
    });
    sort(begin(s2), end(s2), [&](auto i, auto j) {
        if (skill[i][1] == skill[j][1]) {
            return name[i] < name[j];
        }
        return skill[i][1] > skill[j][1];
    });
    sort(begin(s3), end(s3), [&](auto i, auto j) {
        if (skill[i][2] == skill[j][2]) {
            return name[i] < name[j];
        }
        return skill[i][2] > skill[j][2];
    });

    for (;;) {
        while (s1.size() && vis[s1.front()])
            s1.pop_front();
        if (s1.empty()) break;
        int i1 = s1.front();
        s1.pop_front();
        vis[i1] = 1;
        while (s2.size() && vis[s2.front()])
            s2.pop_front();
        if (s2.empty()) break;
        int i2 = s2.front();
        s2.pop_front();
        vis[i2] = 2;
        while (s3.size() && vis[s3.front()])
            s3.pop_front();
        if (s3.empty()) break;
        int i3 = s3.front();
        s3.pop_front();
        vis[i3] = 3;

        vector<string> names = {name[i1], name[i2], name[i3]};
        sort(begin(names), end(names));

        printf("%s %s %s\n", names[0].c_str(), names[1].c_str(), names[2].c_str());
    }
}
