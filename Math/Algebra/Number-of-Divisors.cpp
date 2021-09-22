//Number of divisors for a number n
//If all x prime factors are unique then num of divisors are 2^x
//But if repeating factors then (f1+1)(f2+1)(f3+1).... = num of divisors
//Where f1,f2,f3 is the frequency of each factor
//Time: O(sqrt(n))
//Space: O(log(n)) To store all the factors
#include<bits/stdc++.h>
using namespace std;
void factorize(int n){
	unordered_map<int,int> factors;
	for(long long i=2; i*i<=n; i++){
		while(n%i==0){
			factors[i]++;
			n/=i;
		}
	}
	if(n>1)
		factors[n]++;
	int count = 1;
	for(auto itr: factors){
		count*=(itr.second+1);
	}
	cout << "Number of divisors are " << count << endl;
	return;
}
int main(){
	cout << "Enter n" << endl;
	int n;
	cin >> n;
	factorize(n);
	return 0;
}

