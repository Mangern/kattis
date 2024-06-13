#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ost male, female;

    char buf[30];
    char buf2[30];

    while (true) {
        memset(buf, 0, sizeof buf);
        memset(buf2, 0, sizeof buf2);
        int cmd;
        scanf("%d", &cmd);
        if (!cmd)break;

        if (cmd == 1) {
            string name;
            int gen;
            scanf("%s %d", buf, &gen);
            name = buf;

            if (gen == 1)male.insert(name);
            else female.insert(name);
        } else if (cmd == 2) {
            scanf("%s", buf);
            string name = buf;
            male.erase(name);
            female.erase(name);
        } else {
            string start, end;
            int gen;
            scanf("%s %s %d", buf, buf2, &gen);
            start = buf;
            end = buf2;

            int cnt = 0;

            if (gen ^ 2) {
                //male
                cnt += male.order_of_key(end) - male.order_of_key(start);
            }
            if (gen ^ 1) {
                //female
                cnt += female.order_of_key(end) - female.order_of_key(start);
            }
            printf("%d\n", cnt);
        }
    }
}
