#include<bits/stdc++.h>
using namespace std;
long long int fib(int n,long long int dp[]){
	if(n == 0){
		dp[0] = 0;
		return 0;
	}
	if((n==1) || (n==2)){
		dp[n] = 1;
		return 1;
	}
	long long int temp = 0;
	if(dp[n-1] == -1){
		temp = fib(n-1, dp);
	}
	else{
		temp = dp[n-1];
	}
	if(dp[n-2] == -1){
		temp += fib(n-2, dp);
	}
	else{
		temp += dp[n-2];
	}
	dp[n] = temp;
	return dp[n];
}
int main(){
	cout << "Enter the n to find nth fibonacci number" << endl;
	int n;
	cin >> n;
	long long int dp[n+1];
	for(int i=0; i<n; i++)
		dp[i] = -1;
	fib(n,dp);
	cout << dp[n] << endl;
	return 0;
}
