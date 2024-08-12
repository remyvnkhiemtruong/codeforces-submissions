#include<bits/stdc++.h>
using namespace std;

// Shortcut

#define int long long
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

const int N = 2e5 + 5, mod = 1e9 + 7, inf = 1e9;

int n, ans;
int a[N], pos[N], r[N], l[N];
stack <int> st;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    For(i, 0, n){
        cin >> a[i];
        pos[a[i]] = i;
        while (!st.empty() && a[st.top()] < a[i]){
            r[st.top()] = i - 1;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()){
        r[st.top()] = n - 1;
        st.pop();
    }
    FordE(i, n - 1, 0){
        while (!st.empty() && a[st.top()] < a[i]){
            l[st.top()] = i + 1;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()){
        l[st.top()] = 0;
        st.pop();
    }
    For(i, 0, n){
        if (i - l[i] <= r[i] - i){
            FordE(j, i - 1, l[i]){
                if (pos[a[i] - a[j]] > i && pos[a[i] - a[j]] <= r[i]){
                    ans++;
                }
            }
        }
        else{
            ForE(j, i + 1, r[i]){
                if (pos[a[i] - a[j]] < i && pos[a[i] - a[j]] >= l[i]){
                    ans++;
                }
            }
        }
    }
    cout << ans;
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