//Let, f be some reversible function and A be an array of integers of length N.
//Fenwick tree is a data structure which:
//calculates the value of function f in the given range [l,r] 
//(i.e. f(Al,Al+1,…,Ar)) in O(logn) time;
//updates the value of an element of A in O(logn) time;
//requires O(N) memory, or in other words, exactly the same memory required for A;
//is easy to use and code, especially, in the case of multidimensional arrays.
//Fenwick tree is also called Binary Indexed Tree, or just BIT abbreviated.
//Below is an implementation of finding sum in a fenwick tree
//Time: Query Range = O(log(n))
//Time: Update Range = O(log(n))
#include<bits/stdc++.h>
using namespace std;
struct FenwickTree{
	vector<int> bit;
	int n;
	FenwickTree(int n){
		this->n = n;
		bit.assign(n,0);
	}
	FenwickTree(vector<int> a):FenwickTree(a.size()){
		for(int i=0; i<a.size(); i++)
			add(i, a[i]);
	}
	int sum(int r){
		int ret = 0;
		for(; r>=0; r = (r&(r+1))-1)
			ret += bit[r];
		return ret;
	}
	int sum(int l, int r){
		return sum(r)-sum(l-1);
	}
	void add(int ind, int delta){
		for(; ind<n; ind = ind | (ind +1))
			bit[ind] += delta;
	}
	void print(){
		for(auto itr: bit)
			cout << itr << " ";
		cout << endl;
	}
};
int main(){
	cout << "Enter size of array" << endl;
	int n;
	cin >> n;
	cout << "Enter array" << endl;
	vector<int> a(n);
	for(int i=0; i<n;i++)
		cin >> a[i];
	FenwickTree FT(a);
	cout << "The Fenwick Tree looks like " << endl;
	FT.print();
	cout << "Enter number of queries" << endl;
	cin >> n;
	cout << "Enter queries as L R" << endl;
	for(int i=0; i<n; i++){
		int L,R;
		cin >> L >> R;
		cout << FT.sum(R) - FT.sum(L-1) << endl;
	}
	return 0;
}



