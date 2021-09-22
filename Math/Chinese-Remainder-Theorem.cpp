//We are given two arrays num[0..k-1] and rem[0..k-1]. In num[0..k-1], every pair is coprime (gcd for every pair is 1). We need to find minimum positive number x such that: 
//    x % num[0]    =  rem[0], 
//    x % num[1]    =  rem[1], 
//    .......................
//
//    x % num[k-1]  =  rem[k-1]
//x =  ( ∑ (rem[i]*pp[i]*inv[i]) ) % prod
//   Where 0 <= i <= n-1
//
//rem[i] is given array of remainders
//
//prod is product of all given numbers
//prod = num[0] * num[1] * ... * num[k-1]
//
//pp[i] is product of all divided by num[i]
//pp[i] = prod / num[i]
//
//inv[i] = Modular Multiplicative Inverse of 
//         pp[i] with respect to num[i]
//Time: O(k*min(pp[i],num[i])
//Space: O(k)
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
int modular_inverse(int a,int m){
	int x,y;
	int d = extended_euclidean(a,m,x,y);
	if(d!=1){
		x = -1;
	}
	else{
		x = (x%m + m)%m;
	}
	return x;
}
int inverse_mod_CRT(vector<int> num, vector<int> rem){
	int k = num.size();
	int total = 1;
	vector<int> pp(k);
	for(int i=0; i<k; i++)
		total*=num[i];
	for(int i=0; i<k; i++)
		pp[i] = total/num[i];
	int ans = 0;
	for(int i=0; i<k; i++){
		int temp = (rem[i]*pp[i]*modular_inverse(pp[i],num[i]));
		ans+=temp;
	}
	return ans%total;
}
int main(){
	cout << "Enter size k" << endl;
	int k;
	cin >> k;
	vector<int> num(k),rem(k);
	cout << "Enter x % num = rem as num rem" << endl;
	for(int i=0; i<k; i++)
		cin >> num[i] >> rem[i];
	cout << "x = " << inverse_mod_CRT(num,rem) << endl;
	return 0;
}

