//Sieve of eratosthenes linear version
//Time: O(n)
//Space: O(n) More memory than Normal Sieve
//We stored only boolean true false in normal
//but here we store minimum prime factor for each number
#include<bits/stdc++.h>
using namespace std;
void sieve(int n){
	int lp[n+1] = {0};
	vector<int> primes_found;
	for(int i=2; i<=n; i++){
		if(lp[i]==0){
			lp[i] = i;
			primes_found.push_back(i);
		}
		for(int j=0; j<primes_found.size() && primes_found[j]<=lp[i] && i*primes_found[j]<=n; j++){
			lp[i*primes_found[j]] = primes_found[j];
		}
	}
	for(auto itr: primes_found)
		cout << itr << " ";
	cout << endl;
	return;
}
int main(){
	cout << "Enter n" << endl;
	int n;
	cin >> n;
	sieve(n);
	return 0;
}

