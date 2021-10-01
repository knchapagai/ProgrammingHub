#include<iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

int fun(int m,int n){
    int carry = 0;
    int countCarr = 0;
    int diff = 0;

    for(int i=0; i<3;i++){

        int lastM = m%10;
        m = m/10;
        int lastN = n%10;
        n = n/10;

        if( (lastM + lastN + diff) >= 10 ){
            countCarr++;
            diff = 1;
        }
    }

    return countCarr;
}



int main(){

    int m ;
    cout << "Enter first number" << endl;
    cin >> m;
    int n ;
    cout << "Enter Second Number" << endl;
    cin >> n;

    cout << "Carry happened in the addition : ";
    cout << fun(m,n);

    return 0;




}
