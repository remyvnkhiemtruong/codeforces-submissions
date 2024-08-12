#include <iostream>
#define min(a, b) ((a < b) ? (a) : (b))
using namespace std;

int main(){
    long n, i, tol = 0;
    cin >> n;
    int a[n], b[4] = {0, 0, 0, 0}, temp;
    for (i = 0; i < n; i++){
        cin >> a[i];
        b[a[i] - 1]++;
    }
    tol += b[3];
    temp = min(b[0], b[2]);
    tol += temp;
    b[0] -= temp;
    b[2] -= temp;
    if (b[0] == 0) tol += b[2];
    tol += b[1] / 2;
    b[1] = b[1] % 2;
    tol += b[0] / 4;
    if (b[0] != 0){
        b[0] = b[0] % 4;
        if (b[1] == 1){
            tol += 1;
            b[1] -= 1;
            b[0] -= 2;
        }
        if (b[0] > 0) tol += 1;
    }
    tol += b[1];
    cout << tol;
}