#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[1000], c[1000];
	int sgn = 1;
	int rolling_sum = 0;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		rolling_sum += sgn * a[i];
		sgn *= -1;
	}
	c[1] = rolling_sum / 2;
	for(int i = 2; i <= n; ++i){
		c[i] = a[i-1] - c[i-1];
	}
	for(int i = 1; i <= n; ++i){
		cout << c[i] << '\n';
	}
	return 0;
}
