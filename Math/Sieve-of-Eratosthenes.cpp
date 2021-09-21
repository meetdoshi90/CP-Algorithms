// Sieve of Eratosthenes
// Finding all prime numbers in a range [1:n]
// Time: O(nloglogn)
// Space: O(n)
#include<bits/stdc++.h>
using namespace std;
void sieve(int n){
	vector<bool> isPrime(n+1,true);
	for(int i=2; i<=n; i++){
		if(isPrime[i]){
			cout << i << " ";
			for(long long j=i*i; j<=n; j+=i)
				isPrime[j] = false;
		}
	}
	return;
}
int main(){
	int n;
	cout << "Enter n" << endl;
	cin >> n;
	sieve(n);
	return 0;
}


