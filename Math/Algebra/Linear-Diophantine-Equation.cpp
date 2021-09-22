#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b, int &x, int &y){
	if(b==0){
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = gcd(b,a%b,x1,y1);
	x = y1;
	y = x1-y1*(a/b);
	return d;
}
int main(){
	cout << "Enter a b c" << endl;
	int a,b,c;
	cin >> a >> b >> c;
	int x,y;
	int temp = gcd(a,b,x,y);
	if(c%temp==0){
		cout << "The solution is" << endl;
		cout << a << "*" << x*(c/temp) << " + " << b << "*" << y*(c/temp) << " = " << c << endl;
	}
	else{
		cout << "No solution exists" << endl;
	}
	return 0;
}
