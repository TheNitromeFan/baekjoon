#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int q = m / n, r = m % n;
	long long psum = 1;
	long long powerOf6 = 1;
	for(int i = 0; i < r; ++i){
		psum *= q + 1;
		powerOf6 *= 6;
	}
	for(int i = r; i < n; ++i){
		psum *= q;
		powerOf6 *= 6;
	}
	cout << setprecision(10) << fixed << psum / (double)powerOf6;
	return 0;
}
