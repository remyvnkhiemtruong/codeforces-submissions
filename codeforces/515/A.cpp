#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b, s;
	cin >> a >> b >> s;
	int dis = abs(a) + abs(b);
	if (dis > s){
		cout << "No";
		return 0;
	}
	dis -= s;
	if (dis % 2 == 0){
		cout << "Yes";
		return 0;
	}
	cout << "No";
}