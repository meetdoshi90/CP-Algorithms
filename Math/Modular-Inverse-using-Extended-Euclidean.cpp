//a.x ≡ 1 mod m
//Modular inverse exists if and only if gcd(a,m)=1
//Time: O(log min(a,m))
//Space: O(1)
#include<bits/stdc++.h>
using namespace std;
int extended_euclidean(int a,int b, int& x, int& y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int x1,y1;
	int d = extended_euclidean(b,a%b,x1,y1);
	x = y1;
	y = x1 - y1 * (a/b);
	return d;
}
void modular_inverse(int a,int m){
	int x,y;
	int d = extended_euclidean(a,m,x,y);
	if(d!=1){
		cout << "No inverse exists" << endl;
	}
	else{
		x = (x%m + m)%m;
		cout << a << "*" << x << " =  1 mod " << m << endl;
	}
	return;
}
int main(){
	cout << "Enter a and m" << endl;
	int a,m;
	cin >> a >> m;
	modular_inverse(a,m);
	return 0;
}



