//Time: O(1)
//Space: O(1)
#include<bits/stdc++.h>
using namespace std;
int gray(int n){
	return n^(n>>1);
}
int main(){
	cout << "Enter n" << endl;
	int n;
	cin >> n;
	cout << "Gray of " << n << " is = " << gray(n) << endl;
	return 0;
}
