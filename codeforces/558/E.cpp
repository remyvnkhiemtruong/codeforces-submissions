//#define BITSET64BIT 1
#ifdef BITSET64BIT
#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Optimization

// /*
#pragma GCC optimize("O2,unroll-loops,no-stack-protector")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma comment(linker,"/stack:200000000")
// */
#define endl '\n'

// Shortcut

// #define int long long
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

#define PrintV(a) Fora(h13, a) cout << h13 << ' '; cout << endl;
#define PrintVl(a) Fora(h13, a) cout << h13 << endl;
#define PrintA(a, l, r) for (int h13 = l; h13 <= r; h13++) cout << a[h13] << ' '; cout << endl;
#define PrintAl(a, l, r) for (int h13 = l; h13 <= r; h13++) cout << a[h13] << endl;
#define Ptest(x) return cout << x, 0;
#define getl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
/*
#define debug(args...){                                                                     \\
    string _sDEB = #args;                                                                   \\
    replace(_sDEB.begin(), _sDEB.end(), ',', ' ');                                          \\
    stringstream _ssDEB(_sDEB);                                                             \\
    istream_iterator<string> _itDEB(_ssDEB);                                                \\
    DEB(_itDEB, args);                                                                      \\
}
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

// Policy based data structures                                                             \\
   Support find_by_order(int k): return an iterator to the k-th smallest element,           \\
                                 counting from 0                                            \\
           order_of_key(int k): return the number of items strictly smaller than k          \\
   For ordered_multiset and ordered_multimap, lower_bound() and upper_bound() are swapped

template <typename T> using ordered_set =
tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename Key, typename T> using ordered_map =
tree <Key, T, less <Key>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset =
tree <T, null_type, less_equal <T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename Key, typename T> using ordered_multimap =
tree <Key, T, less_equal <Key>, rb_tree_tag, tree_order_statistics_node_update>;

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

const int N = 1e5 + 5;
int mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
ll infll = 1e18 + 7;

string s;

struct lazy_segment_tree{
    int seg[4 * N][26], lazy[4 * N][26];
    
    lazy_segment_tree(){
        msetn1(lazy);
    }
    
    void down(int id, int l, int r, int i){
        if (lazy[id][i] != -1){
            seg[id][i] = (r - l + 1) * lazy[id][i];
            if (l != r){
                lazy[id << 1][i] = lazy[id][i];
                lazy[id << 1 | 1][i] = lazy[id][i];
            }
            lazy[id][i] = -1;
        }
    }
    
    void build(int id, int l, int r){
        if (l == r){
            seg[id][s[l] - 'a'] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        For(i, 0, 26){
            seg[id][i] = seg[id << 1][i] + seg[id << 1 | 1][i];
        }
    }
    
    void update(int id, int l, int r, int i, int u, int v, int val){
        down(id, l, r, i);
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            lazy[id][i] = val;
            down(id, l, r, i);
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, i, u, v, val);
        update(id << 1 | 1, mid + 1, r, i, u, v, val);
        seg[id][i] = seg[id << 1][i] + seg[id << 1 | 1][i];
    }
    
    int get(int id, int l, int r, int i, int u, int v){
        down(id, l, r, i);
        if (v < l || r < u){
            return 0;
        }
        if (u <= l && r <= v){
            return seg[id][i];
        }
        int mid = (l + r) >> 1;
        return get(id << 1, l, mid, i, u, v) + get(id << 1 | 1, mid + 1, r, i, u, v);
    }
} it;

int n, q;
int cnt[26];

void print(){
    ForE(i, 1, n){
        For(j, 0, 26){
            if (it.get(1, 1, n, j, i, i) == 1){
                cout << (char)(j + 'a');
                break;
            }
        }
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    cin >> s; s = ' ' + s;
    it.build(1, 1, n);
    while (q--){
        int l, r, k; cin >> l >> r >> k;
        For(i, 0, 26){
            cnt[i] = it.get(1, 1, n, i, l, r);
            it.update(1, 1, n, i, l, r, 0);
        }
        if (k){
            int idx = l;
            For(i, 0, 26){
                if (cnt[i]){
                    it.update(1, 1, n, i, idx, idx + cnt[i] - 1, 1);
                    idx += cnt[i];
                }
            }
        }
        else{
            int idx = l;
            FordE(i, 25, 0){
                if (cnt[i]){
                    it.update(1, 1, n, i, idx, idx + cnt[i] - 1, 1);
                    idx += cnt[i];
                }
            }
        }
    }
    print();
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