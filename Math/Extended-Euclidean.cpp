#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b, int& x, int& y){
	if(b==0){
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = gcd(b, a%b, x1, y1);
	x = y1;
	y = x1-y1*(a/b);
	return d;
}

int main(){
	cout << "Enter a b" << endl;
	int a,b;
	cin >> a >> b;
	int x,y;
	int temp = gcd(a,b,x,y);
	cout << "GCD is " << temp << endl;
	cout << a << "*" << x << " + " << b << "*" << y << " = " << temp << endl;
}


