#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
#define For(i, a, b) for (int i = a; i < b; i++)
#define ForE(i, a, b) for (int i = a; i <= b; i++)
#define Ford(i, a, b) for (int i = a; i > b; i--)
#define FordE(i, a, b) for (int i = a; i >= b; i--)
#define Fora(i, a) for (auto i : a)

#define PrintV(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' ';
#define PrintVl(x) for (int i = 0; i < x.size(); i++) cout << x[i] << endl;
#define Ptest(x) return cout << x << endl, 0;
#define isvowel(x) (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y')
#define gl(x) getline(cin, x)

#define pque priority_queue
#define mts multiset
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

vii b;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x;
    cin >> x;
    for (int i = 1; i * i * i <= 8 * x; i++){
        if ((6 * x) % (i * (i + 1))){
            continue;
        }
        long long a = (6 * x) / (i * (i + 1));
        a = a + i - 1;
        if (a % 3){
			continue;
		}
        if (i > a / 3){
			break;
		}
        b.pb(mp(i, a / 3));
    }
    if (b[b.size() - 1].fi == b[b.size() - 1].se){
		cout << 2 * b.size() - 1 << endl;
	}
    else{
		cout << 2 * b.size() << endl;
	}
    For(i, 0, b.size()){
        if (b[i].first == b[i].second){
			continue;
		}
        cout << b[i].first << ' ' << b[i].second << endl;
    }
	FordE(i, b.size() - 1, 0){
        cout << b[i].second << " " << b[i].first << endl;
    }
}

/*
----------------------------------+
INPUT:                            |
==============================    |
26
==============================    |
2
==============================    |
8
==============================    |
----------------------------------+
OUTPUT:                           |
==============================    |
6
1 26
2 9
3 5
5 3
9 2
26 1
==============================    |
2
1 2
2 1
==============================    |
4
1 8
2 3
3 2
8 1
==============================    |
----------------------------------+
*/