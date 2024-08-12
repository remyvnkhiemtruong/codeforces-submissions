#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    int a[n];
    for (int i = 0; i < n; i++){
        a[i] = s[i] - '0';
    }
    bool ck = 1;
    for (int i = 0; i < n; i++){
        if (a[i] % 2 == 0){
            ck = 0;
            break;
        }
    }
    if (ck){
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n - 1; i++){
        if (a[i] % 2 == 0 && a[i] < a[n - 1]){
            swap(s[i], s[n - 1]);
            cout << s;
            return 0;
        }
    }
    for (int i = n - 2; i >= 0; i--){
        if (a[i] % 2 == 0 && a[i] > a[n - 1]){
            swap(s[i], s[n - 1]);
            cout << s;
            return 0;
        }
    }
}