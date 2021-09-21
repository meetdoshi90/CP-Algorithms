#include<bits/stdc++.h>
using namespace std;
long long binexp(int a, int b){
	if(b==0)
		return 1;
	long long partial = binexp(a,b/2);
	if(b%2==1)
		return partial*partial*a;
	return partial*partial;
}
int main(){
	int a,b;
	cout << "Enter a^b as a b" <<endl;
	cin >> a >> b;
	cout << binexp(a,b);
	return 0;
}
