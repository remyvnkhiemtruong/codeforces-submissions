#include<bits/stdc++.h>
using namespace std;

// Shortcut

#pragma optimize ("O3")
//#define int long long
#define endl '\n'
#define eb emplace_back
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define Ford(i, r, l) for (int i = r; i > l; i--)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i : a)

// I/O & Debug

#define PrintV(a) for (int iiii = 0; iiii < a.size(); iiii++) cout << a[iiii] << ' ';
#define PrintVl(a) for (int iiii = 0; iiii < a.size(); iiii++) cout << a[iiii] << endl;
#define PrintA(a, n) for (int iiii = 0; iiii < n; iiii++) cout << a[iiii] << ' ';
#define PrintAl(a, n) for (int iiii = 0; iiii < n; iiii++) cout << a[iiii] << endl;
#define Ptest(x) return cout << x, 0;
#define gl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
/*
#define debug(args...){ string _sDEB = #args; replace(_sDEB.begin(), _sDEB.end(), ',', ' '); stringstream _ssDEB(_sDEB); istream_iterator<string> _itDEB(_ssDEB); DEB(_itDEB, args); }
void DEB(istream_iterator<string> it) {}
template<typename T, typename... Args>
void DEB(istream_iterator<string> it, T a, Args... args){
    cout << *it << " = " << a << endl;
    DEB(++it, args...);
}
*/

// Functions

//#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define bend(a) a.begin(), a.end()
#define rbend(a) a.rbegin(), a.rend()
#define mset(a) memset(a, 0, sizeof(a));
#define mmset(a) memset(a, 0x3f, sizeof(a));
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

// Data Structure

#define pque priority_queue
#define mts multiset
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ld> vld;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <vi > vvi;
typedef vector <vll > vvll;
typedef vector <pii > vpii;
typedef vector <pll > vpll;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n, m;
int a[N], cnt[N];
vi adj[N];

bool cmp(pii x, pii y){
    if (x.fi != y.fi) return x.fi < y.fi;
    return x.se > y.se;
}

set <pii, decltype(&cmp)> s(&cmp);

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ForE(i, 1, m){
        int u, v;
        cin >> u >> v;
        cnt[u]++;
        adj[v].pb(u);
    }
    ForE(i, 1, n){
        s.insert({cnt[i], i});
    }
    ForE(i, 1, n){
        auto u = *s.begin();
        s.erase(s.begin());
        //cout << u.fi << ' ' << u.se << endl;
        a[u.se] = n + 1 - i;
        Fora(v, adj[u.se]){
            //cout << v << endl;
            if (a[v]){
                continue;
            }
            s.erase({cnt[v], v});
            s.insert({cnt[v] - 1, v});
            cnt[v]--;
        }
        cnt[u.se] = 0;
        //for (auto itr = s.begin(); itr != s.end(); itr++){
        //    cout << (*itr).fi << ' ' << (*itr).se << endl;
        //}
        //cout << endl;
    }
    ForE(i, 1, n){
        cout << a[i] << ' ';
    }
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/