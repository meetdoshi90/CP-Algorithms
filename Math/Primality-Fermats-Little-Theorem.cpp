// To check if a number is prime or not using Fermats Little Theorem
// Time: O(iter*log(n))
// Space: O(1)
// Negativity test with chance of getting false positive
// Read more about carmicheal numbers
#include<bits/stdc++.h>
using namespace std;
long long binpower(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
bool isPrime(int n, int iter=5) {
    if (n < 4)
        return n == 2 || n == 3;

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (binpower(a, n - 1, n) != 1)
            return false;
    }
    return true;
}
int main(){
	cout << "Enter number to check for primality" << endl;
	int n;
	cin >> n;
	string ans = (isPrime(n,10)?"Prime":"Not Prime");
	cout << ans << endl;
	return 0;
}
