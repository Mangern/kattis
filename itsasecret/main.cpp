#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
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
const int mxN = 2e5+6;
const ll MOD  = 1e9+7;

int row(string& key, char c) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) if (key[i * 5 + j] == c)return i;
    }
    cout << c << endl;
    assert(false);
}
int col(string& key, char c) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) if (key[i * 5 + j] == c)return j;
    }
    assert(false);
}

string encrypt(string s, string key) {
    transform(all(s), begin(s), [](char c) { return toupper(c == 'J' ? 'I' : c); });
    int n = s.length();
    string t;
    for (int i = 0; i < n; ++i) {
        if (s[i] == ' ') continue;
        char c = s[i];
        if (t.size() % 2 == 1 && t.back() == c)t.push_back('X');
        t.push_back(c);
    }
    n = t.length(); s = t; if (n & 1) { s.push_back('X'); ++n; }

    string res;

    for (int i = 0; i < n; i += 2) {
        char a = s[i];
        char b = s[i+1];

        int ra = row(key, a);
        int ca = col(key, a);
        int rb = row(key, b);
        int cb = col(key, b);

        if (a == 'X' && b == 'X') {
            res.push_back('Y');
            res.push_back('Y');
        } else if (ra == rb) {
            res.push_back(key[ra * 5 + (ca+1)%5]);
            res.push_back(key[ra * 5 + (cb+1)%5]);
        } else if (ca == cb) {
            res.push_back(key[((ra + 1) % 5) * 5 + ca]);
            res.push_back(key[((rb + 1) % 5) * 5 + ca]);
        } else {
            res.push_back(key[ra * 5 + cb]);
            res.push_back(key[rb * 5 + ca]);
        }
    }
    return res;
}

bool has = 0;
void testCase() {
    string sn;
    getline(cin, sn);
    int n = stoi(sn);
    if (!n)exit(0);

    if (has)cout << endl;
    has = 1;
    string keys;
    getline(cin, keys);
    transform(all(keys), begin(keys), [](char c) { return toupper(c); });

    string key;
    set<char> rem;
    for (char c = 'A'; c <= 'Z'; ++c) if (c != 'J')rem.insert(c);

    for (char c : keys) {
        if (c == ' ') continue;
        if (c == 'J')c = 'I';
        if (key.length() == 25)break;
        if (!rem.count(c))continue;
        key.push_back(c);
        rem.erase(c);
    }
    while (key.size() < 25) {
        key.push_back(*rem.begin());
        rem.erase(rem.begin());
    }
    //cout << key << endl;

    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);

        cout << encrypt(s, key) << endl;
    }
}

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {

}

int main() {
    setIO();
    pre();
    int t = 50;
    //cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        testCase();
    }
    return 0;
}
