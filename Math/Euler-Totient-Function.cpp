//Also called phi function 
//Counts the number of integers from 1 to n which are coprime to n
//Two numbers are coprime if their gcd is 1
//Time: O(nloglogn)
//Space: O(n)
#include<bits/stdc++.h>
using namespace std;
void phi(int n){
	vector<int> cop(n+1);
	for(int i=0; i<=n; i++)
		cop[i] = i;
	for(int i=2; i<=n; i++){
		if(cop[i]==i){
			for(int j=i; j<=n; j+=i)
				cop[j] -= cop[j]/i;
		}
	}
	for(int i=1; i<=n; i++){
		cout << i << " = " << cop[i] << endl;
	}
	return;
}
int main(){
	cout << "Enter n" << endl;
	int n;
	cin >> n;
	phi(n);
	return 0;
}


