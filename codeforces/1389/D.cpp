#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Optimization

//#pragma GCC optimize("O3")
#define endl '\n'

// Shortcut

#define int long long
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

#define PrintV(a) Fora(iiii, a) cout << iiii << ' '; cout << endl;
#define PrintVl(a) Fora(iiii, a) cout << iiii << endl;
#define PrintA(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << ' '; cout << endl;
#define PrintAl(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << endl;
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
#define mset(a) memset(a, 0, sizeof(a))
#define mset1(a) memset(a, 1, sizeof(a))
#define msetn1(a) memset(a, -1, sizeof(a))
#define msetinf(a) memset(a, 0x3f, sizeof(a))
#define gcd __gcd
#define __builtin_popcount __builtin_popcountll
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
//int randt(int l, int r){ return (rando() % (r - l + 1) + l); }

// Data Structure

#define pque priority_queue
#define mts multiset
#define y0 _y0_
#define y1 _y1_
#define div divi
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

const int N = 2e5 + 5;
int mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
ll infll = 1e18 + 7;

int n, k;
int l1, r1, l2, r2;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    cin >> n >> k;
    cin >> l1 >> r1 >> l2 >> r2;
    if (!(r1 < l2 || r2 < l1)){
        int I = (min(r1, r2) - max(l1, l2)) * n;
        if (I >= k){
            cout << 0 << endl;
            continue;
        }
        int kek = 2 * (max(r1, r2) - min(l1, l2)) - (r1 - l1) - (r2 - l2);
        if (I + kek * n >= k){
            cout << k - I << endl;
            continue;
        }
        I += kek * n;
        cout << kek * n + (k - I) * 2 << endl;
        continue;
    }
    int kek1 = max(l1, l2) - min(r1, r2), kek2 = max(r1, r2) - min(l1, l2);
    if (k <= kek2){
        cout << kek1 + k << endl;
        continue;
    }
    if (kek1 > kek2){
        cout << kek1 + kek2 + 2 * (k - kek2) << endl;
        continue;
    }
    bool ckkk = 0;
    int ans = kek1 + kek2;
    k -= kek2;
    ForE(i, 2, n){
        if (k <= kek2){
            ans += min(kek1 + k, 2 * k);
            ckkk = 1;
            break;
        }
        else{
            ans += kek1 + kek2;
            k -= kek2;
        }
    }
    if (!ckkk){
        ans += 2 * k;
    }
    cout << ans << endl;
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