/*
Treap is a data structure which combines binary tree and binary heap 
(hence the name: tree + heap = Treap).
More specifically, treap is a data structure that stores pairs (X, Y)
in a binary tree in such a way that it is a binary search tree by X
and a binary heap by Y. Assuming that all X and all Y are different,
we can see that if some node of the tree contains values (X0, Y0), 
all nodes in the left subtree have X<X0, all nodes in the right subtree have X>X0, 
and all nodes in both left and right subtrees have Y<Y0.
Time: 
	Insert (X,Y) O(logn)
	Search X O(logn)
	Erase X O(logn)
	Build (X1...Xn) O(N)
	Union (T1,T2) O(Mlog(N/M))
	Intersect (T1,T2) O(Mlog(N/M))
*/
#include<bits/stdc++.h>
using namespace std;
struct item{
	int key, prior, cnt;
	item *l, *r;
	item (){}
	item (int key) : key(key),prior(rand()),l(NULL),r(NULL){}
};
typedef item* pitem;
void split(pitem t, int key, pitem &l ,pitem &r){
	if(!t)
		l = r = NULL;
	else if(t->key <= key)
		split(t->r, key, t->r, r), l=t;
	else
		split(t->l, key, l, t->l), r=t;
}
void insert (pitem & t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split (t, it->key, it->l, it->r),  t = it;
    else
        insert (t->key <= it->key ? t->r : t->l, it);
}

void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
}

void erase (pitem & t, int key) {
    if (t->key == key) {
        pitem th = t;
        merge (t, t->l, t->r);
        delete th;
    }
    else
        erase (key < t->key ? t->l : t->r, key);
}

pitem unite (pitem l, pitem r) {
    if (!l || !r)  return l ? l : r;
    if (l->prior < r->prior)  swap (l, r);
    pitem lt, rt;
    split (r, l->key, lt, rt);
    l->l = unite (l->l, lt);
    l->r = unite (l->r, rt);
    return l;
}
int cnt (pitem t) {
    return t ? t->cnt : 0;
}

void upd_cnt (pitem t) {
    if (t)
        t->cnt = 1 + cnt(t->l) + cnt (t->r);
}
void heapify (pitem t) {
    if (!t) return;
    pitem max = t;
    if (t->l != NULL && t->l->prior > max->prior)
        max = t->l;
    if (t->r != NULL && t->r->prior > max->prior)
        max = t->r;
    if (max != t) {
        swap (t->prior, max->prior);
        heapify (max);
    }
}
pitem build (int * a, int n) {
    // Construct a treap on values {a[0], a[1], ..., a[n - 1]}
    if (n == 0) return NULL;
    int mid = n / 2;
    pitem t = new item (a[mid] );
    t->l = build (a, mid);
    t->r = build (a + mid + 1, n - mid - 1);
    heapify (t);
    upd_cnt(t);
    return t;
}
void print(pitem root){
	if(!root)
		return;
	cout << root->key << " " << root->prior << endl;
	print(root->l);
	print(root->r);
	return;
}
int main(){
	pitem root = nullptr;
	cout << "Enter size of treap" <<endl;
	int n;
	cin >> n;
	cout << "Enter array elements" << endl;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
	root = build(arr,n);
	print(root);
	return 0;
}



