#include <bits/stdc++.h>
using namespace std;

/*

Program to print the following pattern 

 	* 
   * * 
  * * *                                                                                                                 
 * * * *                                                                                                                
* * * * * 

*/

int main(){
	int n;
	cout<<"Number of Rows: ";
	cin>> n;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			(j < n-i+1)? cout<< " ": cout<< "* ";
		}
		cout<< endl;
	}
	return 0;
}