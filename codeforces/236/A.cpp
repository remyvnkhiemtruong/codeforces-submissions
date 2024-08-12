#include<iostream>
#include<string>
using namespace std;

int main(){
    bool a[26];
    int len, i, t = 0;
    string n;
    for (i = 0; i < 26; i++) a[i] = 0;
    cin >> n;
    len = n.length();
    for (i = 0; i < len; i++){
        if (!a[(int) n[i] - 97]){
            t++;
            a[(int) n[i] - 97] = 1;
        }
    }
    if (t % 2 == 0) cout << "CHAT WITH HER!";
    else cout << "IGNORE HIM!";
}