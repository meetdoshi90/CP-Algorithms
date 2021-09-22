#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
void fft(vector<complex<double>>& a){
	int n = a.size();
	if(n==1)
		return;
	vector<complex<double>> a0(n/2),a1(n/2);
	for(int i=0; 2*i < n; i++){
		a0[i] = a[2*i];
		a1[i] = a[2*i+1];
	}
	fft(a0);
	fft(a1);
	double ang = -1 * ((2*PI)/n);
	complex<double> w(1), wn(cos(ang), sin(ang));
	for(int i=0; 2*i < n; i++){
		a[i] = a0[i] + w*a1[i];
		a[i+n/2] = a0[i] - w*a1[i];
		w *= wn;
		if(real(w)<0.000001 && real(w)>-0.000001)
			w = complex<double>(0,imag(w));
	}
}

int main(){
	cout << "Enter a power of 2 point time sequence" << endl;
	cout << "Enter size" << endl;
	int n;
	cin >> n;
	cout << "Enter sequence as Real Imaginary pair" << endl;
	vector<complex<double>> seq(n);
	for(int i=0; i<n; i++){
		int real_part;
		int img_part;
		cin >> real_part >> img_part;
		complex<double> temp(real_part, img_part);
		seq[i]= temp;
	}
	fft(seq);
	cout << "DIT FFT Radix 2 in reversed index format" << endl;
	for(int i=0; i<n; i++){
		cout << real(seq[i]) << " + " << imag(seq[i]) << "j" << endl;
	}
	return 0;
}



