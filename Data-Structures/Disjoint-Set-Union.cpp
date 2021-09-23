//make_set(v)
//union_sets(a, b)
//find_set(v)
//These operations can be done in O(1) in average
//Uses path compression and union by size/rank
//The final amortized time complexity is O(α(n)), where α(n) is the inverse Ackermann function
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> parent,size;
int find_set(int v){
	if(v==parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
void make_set(int v){
	parent[v] = v;
	size[v] = 1;
}
void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		if(size[a] < size[b])
			swap(a,b);
		parent[b] = a;
		size[a] += size[b];
	}
}
int main(){
	cout  << "Enter num of elements" << endl;
	int n;
	cin >> n;
	for(int i=0 ; i<n; i++){
		int temp;
		cin >> temp;
		make_set(temp);
	}
	cout << "Enter number of queries" << endl;
	cin >> n;
	cout << "Enter union queries as a b pair" << endl;
	for(int i=0; i<n; i++){
		int a,b;
		cin >> a >> b;
		union_set(a,b);
	}
	cout << "The tree structure is" << endl << "Node Size Parent" << endl;
	for(auto node: parent){
		cout << node.first << " " << size[node.first]<< " " << node.second << endl;
	}
	return 0;
}
	
