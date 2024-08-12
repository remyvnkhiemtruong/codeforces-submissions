#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    s = '0' + s;
    int n = s.length();
    int ans = s[n - 2] * 10 + s[n - 1];
    ans %= 4;
    switch (ans){
        case 0: cout << 4; return 0;
        case 1: cout << 0; return 0;
        case 2: cout << 0; return 0;
        case 3: cout << 0; return 0;
    }
}