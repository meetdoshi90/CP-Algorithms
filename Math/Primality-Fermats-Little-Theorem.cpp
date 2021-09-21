// To check if a number is prime or not
// Time: O(sqrt(n))
// Space: O(1)
#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n){
	for(int i=2; i*i<=n; i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main(){
	cout << "Enter number to check for primality" << endl;
	int n;
	cin >> n;
	string ans = (isPrime(n)?"Prime":"Not Prime");
	cout << ans << endl;
	return 0;
}
