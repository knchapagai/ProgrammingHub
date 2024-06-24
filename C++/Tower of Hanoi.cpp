//Tower of hanoi

#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void solve(int n, int src, int des, int help) {
	if(n==1){
		cout<<"Move plate from "<<src<<" to "<<des<<"\n";
		cnt++;
		return;
	}
	else{
		solve(n-1, src, help, des);
		cout<<"Move plate from "<<src<<" to "<<des<<"\n";
		cnt++;
		solve(n-1, help, des, src);
		return;
	}
}

int main(){
	int a=1, b=2, c=3;
	int no_of_plates = 3;
	solve(no_of_plates, a, b, c);
	cout<<"Steps taken: "<<cnt<<"\n";
	return 0;
}