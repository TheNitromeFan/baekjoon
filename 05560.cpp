#include <iostream>
#include <vector>
#include <cstdlib>
#define MOD 100000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> psum(n + 1);
	for(int i = 2; i <= n; ++i){
		int x;
		cin >> x;
		psum[i] = psum[i - 1] + x;
	}
	int pos = 1;
	int dist = 0;
	for(int j = 0; j < m; ++j){
		int aj;
		cin >> aj;
		dist += abs(psum[pos + aj] - psum[pos]);
		dist %= MOD;
		pos += aj;
	}
	cout << dist;
	return 0;
}
