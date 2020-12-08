#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> x(m), y(m);
	for(int i = 0; i < m; ++i){
		cin >> x[i] >> y[i];
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	long long ans = 0;
	for(int i = 0; i < m; ++i){
		ans += abs(x[i] - x[m / 2]) + abs(y[i] - y[m / 2]);
	}
	cout << ans;
	return 0;
}
