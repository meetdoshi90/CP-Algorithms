//Factorization of n into its prime factors
//Time: O(sqrt(n))
//Space: O(1)
#include<bits/stdc++.h>
using namespace std;
vector<long long> factorizer(long long n){
	vector<long long> factors;
	for(long long i=2; i*i<=n; i++){
		while(n%i==0){
			factors.push_back(i);
			n/=i;
		}
	}
	if(n>1)
		factors.push_back(n);
	return factors;
}
int main(){
	cout << "Enter number to be factorized" << endl;
	int n;
	cin >> n;
	vector<long long> ans = factorizer(n);
	for(auto itr: ans)
		cout << itr << " ";
	cout << endl;
	return 0;
}
	
