#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long k, m;
	cin >> n >> k >> m;
	long long q = m / (2 * (n - 1) * k), r = m % (2 * (n - 1) * k);
	vector<long long> players(n);
	for(int i = 0; i < n; ++i){
		if(i == 0 || i == n - 1){
			players[i] = q * k;
		}else{
			players[i] = 2 * q * k;
		}
	}
	for(int i = 0; i < n - 1 && r > 0; ++i){
		players[i] += min(r, k);
		r -= min(r, k);
	}
	for(int i = n - 1; i > 0 && r > 0; --i){
		players[i] += min(r, k);
		r -= min(r, k);
	}
	for(int i = 0; i < n; ++i){
		cout << players[i] << ' ';
	}
	return 0;
}
