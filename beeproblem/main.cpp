#include <bits/stdc++.h>
/*MMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNXXKK0KXXXXXXNNNWWWMMMMMMMMMMMMMMMMMMMMMMMMMMM*/
using namespace std;/*MMMMMMWKklc:codl:clldxkkxxkkOXNWMMMMMMMMMMMMMMMMMMMMMMMM*/
using ll=long long;/*MMMMWXkl,...',cddc,,,,:oxkxdooox0NMM*/using ld=long double;
const int/*MMMMMMMWNXK0kxd:........,cdxdoc,';lxOkxdoc:oK*/INF=numeric_limits<int
>::max();/*MMMMMW0oc:;,''..........';cdkkxc'',cdkkddoc;dN*/const ll INFLL=/*MM*/
/*MMMMMMMMMMMMMM0;.............  ....,cdxxo,',:oxkxolooxXM*/numeric_limits<ll>::
max();using vi/*x..   ......        ..,codo:,,:dO0xoccco0W*/=vector<int>;/*MMM*/
template</*MMMMWO;.   .. .           ..;:::::;:lxxdolc:cxN*/typename t, /*MMMM*/
size_t N>/*MMMMMNk:. ...             ..';;:cllloooc:::::lONMMMMMMMMMMMMMMMMMMM*/
using ar=/*MMMMMWKko:,..            ...,:clllooodoc;,,,,:o0WMMMMMMMMMMMMMMMMMM*/
array<t,N>;/*MMWXXXKk:..    .     ....':ccllllllllc:,'.',:xN*/using ii=array<ll,
2>;using vii=/*X0X0kd:.     .    ....';ccllllllllllc:,..':OW*/vector<ii>;/*MMM*/
using vll=/*MWKxlc,....     .  ......;:ccllllllcc:;;;,,,ckX*/vector<ll>;/*MMMM*/
template</*MNk;..      ..    .......',;;;::cllcc;,,,,,cldXM*/typename t> istream
& operator/*d'.       .....  ....',;,'',;;:cllc:;'..,:dkxKM*/>>(istream& in,/**/
vector<t>/*0c..        ........';:;,...',,:clllc:;;;:oO0xkW*/&vec){for(t& x:vec)
{in>>x;}/*W0:..         ......';cc:::;::::cllloollccclxOdxW*/return in;}/*MMMM*/
template</*No'. ...      .....,:cllllcccclllllooolllloO0xKM*/typename t>ostream&
operator<</*Kxc'....      ..',;:cllolllllllllllooolllxKKXW*/(ostream& os,vector<
t>& vec){/*MMWN0o,.......:l:l0KkllooooollllllccclllldOXNWMM*/for(int i=0;i< vec.
size();++i){os<<vec[i];/*NNOlOWWOllooooooollc:;;::coxKWM*/if(i<vec.size()-1)os<<
" ";}return os;}/*MMMMMMMMMMMMMMKoclloooolc;,'''';lx0NWWWMMWWWWWWWWWMMMMMMMMMM*/
#define all(v) begin(v), /*MKONWOl:cclllllllc::::lxxdk0KKKKKXXX*/end(v)/*MMMMM*/
mt19937_64 rng(chrono::/*MMW0O0xc::cccccllllllccclk0dloddddxkkk00K*/steady_clock
::now().time_since_epoch/*Xkl::;;:ccccccccccc::::cdOklcoxxxdoooodddxkO*/().count
());ll myRand(ll B){/*WXOxl:;;;;;:ccclcccccc::::::clollodxdolllllllllodk*/return
(uint64_t)rng()%B;}/*Oxolc::::;;;:cccccccccccccc::cloolccooolllllllllllox0NMMM*/
template<typename/*dolllc:;;::;:::::::cccc:ccccclllllcc;:looollllllllclloxKM*/t> 
t min(const/*0kdollllllll:;;::::::;;;:::ccc:::cllllcccc:;cooolccllllccll*/vector
<t>& v){/*kkxoollllclllolcccllccccccccccccc:;:ccllcclllc:cooollccclcclcc*/return
*min_element/*llllcclllllc:cllllllllllllllc::ccccclllllc:cloollcccccccccl*/(all(
v));}/*W0olllllllllclllllc::ccllllllllllllllllllllllllllclloollc:cccccccclkNMM*/
template/*olllllllllllolol::ccllllllllllllllllllllllllllllcldolc::ccccccclOWM*/<
typename/*oollllcllllloooocccllllllllllllllllllllcccllllolclddoc;:ccccccclOW*/t>
t max(/*Kdoolllllllllloooolcclllllloolllllllllcccccclllooolloddl:;:cccccl*/const
vector</*doollllllllllooooolccllloooooollllllcccccclllooooolodddl::cccccldKK*/t>
& v){/*MXxooolllllcccclooooollllooooddoooolccc::cccllooodddoodddoc:ccccc*/return
*max_element(/*lllcc:;cooooooooooddxkOkxddolc:::cclllooooddddddddocccllllx*/all(
v));}/*MW0ooooollllcc;;loodooodxk0KXNNNXKOdl:;;:cclllloooooooddddolcccc:oKWMMMMM
MMMMMMMMMXxllooollllc::looddddk0KXNNWWWNNKxoc,,:cllllllooooooddddolc::::xNMMMMMM
MMMMMMMMMWKdoloollllc:cooodxkO0KXXXNNNNNNKxol;,cllllllllllllodoooolcc::cOWMMMMMM
MMMMMMMMMMWX0xoooollcclooddk0000KKXXXNNXX0xol:,:lloollllccllooooollcc::dXMMMMMMM
MMMMMMMMMMMMMN0dllllcccooodxkkOO00KKKXXKKOdol:,;llooollcclllllllllc:::l0WMMMMMMM
MMMMMMMMMMMMMMWOlcccc:coooooddxxxkOO0000Oxoll:,,clooollllllllllccc::::xNMMMMMMMM
MMMMMMMMMMMMMMMNxccccccooooooooooooddxxddollc;..;clllllloolllccc:::::oXMMMMMMMMM
MMMMMMMMMMMMMMMW0ocllcclodooooooolllllllcccc:,..';:cllooolllcc::::::l0WMMMMMMMMM
MMMMMMMMMMMMMMMMNxccllccloodooooooolllcccc::;'.';:llllllllcc:::::::lOWMMMMMMMMMM
MMMMMMMMMMMMMMMMMKoccllcclodddooooolllllccccc:ccccc::::;;;;;;::ccclOWMMMMMMMMMMM
MMMMMMMMMMMMMMMMMWOlclllc::clooooolllcccccc::::ccc::;,'.',;::cclclOWMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMNxccllcc:;;;::cccccc:::::;;;cccc::;'',;::clllccdNMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMWW0lcccccc:;,'.,;::::cc::::;:ccc::;'';:cclllcc:c0MMMMMMMMMMMMMM
MMMMMMMMMMMMMMMWNKOdcccccc::;;,'',;;:::::::;:ccc::;,,;:cllllcc:cxNMMMMMMMMMMMMMM
MMMMMMMMMMMWNXXK0xlc::ccccc::;;,''',;:::::;;:cc::;'';ccllllcc::dXMMMMMMMMMMMMMMM
MMMMMMMMMMNXKK0kocc:::cclllccc::,'',;;;;;;,,;::;;,';clllllcc::l0WMMMMMMMMMMMMMMM
MMMMMMMWNXK00Oxlc::::::cllllllcc:;,,;;::::;;;::;,';:cllllcc::lkKWMMMMMMMMMMMMMMM
MMMMMMMKkxkOOxlc:::::::cllllllllc:;,,;;:::::::;,',:cllllcc::lkKXNWMMMMMMMMMMMMMM
MMMMMMWKkkOkdcc:::::::::cllllcllcc:,,,;;;;;;;;,'';cllllccc:cxKXNNNWWMMMMMMMMMMMM
MMMMMMXkdoccc::::::c::;:cllllccccc:;,;;;;;;;;;,',:clllcc::lkKKKXXKKNWMMMMMMMMMMM
MMMMMMKo:::::::::cc::;;::clllccccc:;,,,;;;;;;,'';cccccc::cxKXXKKKKKNMMMMMMMMMMMM
MMMMMMWOc:::::::cc:;;;:::ccllcccccc:,,,,,,,'''',:ccccc::;;ckXNXKKXXNMMMMMMMMMMMM
MMMMMMMNx::::cccc:;;;::;::ccccccccc:;,',,,''..';ccccc:::::;:dKXXKKXNWMMMMMMMMMMM
MMMMMMMKoc::cccc:;;;::::;;::ccccccc:;,'''''..';:cccc::::cc:;;lOXXKKXWMMMMMMMMMMM
MMMMMMM0l::ccc:;;;:::::::;,;:ccccccc:;''''''',:cccc:;;:clllc:;ckKXXWMMMMMMMMMMMM
MMMMMMMWOlcc::;,;::::::::;,;::ccccccc:,'.'.',;:ccc:;;;:cllllc::lONMMMMMMMMMMMMMM
MMMMMMMMW0oldkdc::::::::;;;;;::ccccccc;''''';:ccc:;:::;:clllccco0WMMMMMMMMMMMMMM
MMMMMMMMMMNKNMW0l::::::;;;;;;;::cccccc:,''',;ccc::::::;;:llcccoONMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMWk:;:::;;;;;;;;,,:cccccc;,'',;::cccc:;;;;;:ccclkKNMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMXo;;;::::::;;;,,;:ccccc:;,',;;:ccccc::ccccclox0XWMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMW0l;;:::::::;;;,,;:ccccc::,,;,;::cccccccccldO0KXWMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMWOc;::::::::;;;;;::cccccc:,,'',;;:::::cccokKK0XWMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMXo;::::::::;;;;;::cccccc:;''..',,;::::clx0KK0XWMMMMMMMMMMMMM*/
#define FORMASK(i, mask) for (int _x = (mask), i; i = 31-__builtin_clz(_x&(-_x)), _x; _x -= (_x&-_x)) 
struct UnionFind {
    int num_sets;
    vi p, sz, rnk;
    UnionFind(int n) {
        num_sets = n;
        p = vi(n);
        iota(all(p),0);
        rnk = vi(n,0);
        sz = vi(n,1);
    }

    int find(int i) {
        if (p[i] == i)return i;
        return p[i] = find(p[i]);
    }

    bool check(int i, int j) {
        return find(i)==find(j);
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)return 0;
        if (rnk[i] < rnk[j]) {
            sz[j] += sz[i];
            p[i] = j;
        } else {
            sz[i] += sz[j];
            p[j] = i;
            if (rnk[i] == rnk[j]) {
                ++rnk[i];
            }
        }
        --num_sets;
        return 1;
    }
};
const int mxN = 2e5+6;
const ll MOD  = 1e9+7;

string grid[mxN];

ii delta[2][6] = {
    {
        {-1,-1},
        {-1, 0},
        { 0, 1},
        { 1, 0},
        { 1,-1},
        { 0,-1}
    },
    {
        {-1, 0},
        {-1, 1},
        { 0, 1},
        { 1, 1},
        { 1, 0},
        { 0,-1}
    }
};

void testCase() {
    ll h, n, m;
    cin >> h >> n >> m;

    for (int i = 0; i < n; ++i) {
        grid[i].clear();
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            grid[i].push_back(c);
        }
    }

    UnionFind uf(n * m);

    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if (grid[i][j] == '#') continue;
        for (int k = 0; k < 6; ++k) {
            auto [di, dj] = delta[i&1][k];
            int ni = i + di;
            int nj = j + dj;
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (grid[ni][nj] == '#') continue;
            uf.join(i * m + j, ni * m + nj);
        }
    }

    set<ll> pars;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if (grid[i][j] == '#') continue;
        pars.insert(uf.find(i * m + j));
    }

    vll groups;
    for (auto p : pars)groups.push_back(uf.sz[p]);

    sort(all(groups));
    reverse(all(groups));

    ll ans = 0;

    for (auto g : groups) {
        if (h <= 0) break;
        ans += 1;
        h -= g;
    }
    cout << ans << endl;
}

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {

}

int main() {
    setIO();
    pre();
    int t = 1;
    //cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        testCase();
    }
    return 0;
}
