//Sparse Table is a data structure, that allows answering range queries. 
//It can answer most range queries in O(logn), but its true power is answering
//range minimum queries (or equivalent range maximum queries). 
//For those queries it can compute the answer in O(1) time.
//Below is an implementation of Range Min query sparse table
#include<bits/stdc++.h>
using namespace std;
int main(){
	cout << "Enter array size" << endl;
	int n;
	cin >> n;
	int arr[n] = {0};
	cout << "Enter array" << endl;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	int log[n+1] = {0};
	log[1] = 0;
	for(int i=2; i<=n; i++)
		log[i] = log[i/2]+1;
	int k = log[n]+1;
	int spt[n][k+1] = {{0}};
	for(int i=0; i<n; i++)
		spt[i][0] = arr[i];
	for(int j=1; j<=k; j++)
		for(int i=0; i+(1<<j) <= n; i++)
			spt[i][j] = min(spt[i][j-1], spt[i +(1<<(j-1))][j-1]);
	cout << "Enter query size" << endl;
	int q;
	cin >> q;
	cout << "Enter L R queries" << endl;
	for(int i=0; i<q; i++){
		int L,R;
		cin >> L >> R;
		int j = log[R-L+1];
		cout << min(spt[L][j], spt[R-(1<<j)+1][j]) << endl;
	}
	return 0;
}
