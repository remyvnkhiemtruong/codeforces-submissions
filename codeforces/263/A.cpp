#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int i, j, ii, jj, ans;
    int a[5][5];
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            cin >> a[i][j];
            if (a[i][j] == 1){
                ii = i;
                jj = j;
            }
        }
    }
    ans = abs(ii - 2) + abs(jj - 2);
    cout << ans;
}