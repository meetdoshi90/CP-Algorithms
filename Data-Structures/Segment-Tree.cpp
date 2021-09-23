//A Segment Tree is a data structure that allows answering range 
//queries over an array effectively, while still being flexible enough 
//to allow modifying the array. This includes finding the sum of 
//consecutive array elements a[l…r], or finding the minimum element in a such a range in O(logn) time.
//One important property of Segment Trees is, that they require only 
//a linear amount of memory. 
//The standard Segment Tree requires 4n vertices for working on an array of size n.
//Time: O(log(n)) Query and Update
//Space: O(n)
#include<bits/stdc++.h>
using namespace std;
void build(int a[], int seg_tree[], int ind, int L, int R){
	if(L==R)
		seg_tree[ind] = a[L];
	else{
		int M = (L+R)/2;
		build(a,seg_tree,ind*2, L, M);
		build(a,seg_tree,ind*2+1, M+1, R);
		seg_tree[ind] = seg_tree[ind*2] + seg_tree[ind*2+1];
	}
}
int sum(int v, int seg_tree[], int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return seg_tree[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2,seg_tree, tl, tm, l, min(r, tm))
           + sum(v*2+1,seg_tree, tm+1, tr, max(l, tm+1), r);
}
int main(){
	int n;
	cout << "Enter array size" << endl;
	cin >> n;
	cout << "Enter array elements" << endl;
	int arr[n] = {0};
	int seg_tree[4*n] = {0};
	for(int i=0; i<n; i++)
		cin >> arr[i];
	build(arr,seg_tree,1,0,n-1);
	cout << "Enter query size" << endl;
	cin >> n;
	for(int i=0; i<n; i++){
		int L,R;
		cin >> L >> R;
		cout << sum(1,seg_tree,0,n-1,L,R) << endl;
	}
	return 0;
}



