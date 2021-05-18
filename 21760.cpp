#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		long long n, m, k, d;
		cin >> n >> m >> k >> d;
		long long b = d / (k * n * m * (m - 1) / 2 + n * (n - 1) / 2 * m * m);
		cout << (b ? b * (k * n * m * (m - 1) / 2 + n * (n - 1) / 2 * m * m) : -1) << '\n';
	}
	return 0;
}
