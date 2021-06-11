#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long q;
	cin >> n >> q;
	long long p, k, c;
	cin >> p >> k >> c;
	long long intervals = q / k;
	if(q % k == 0){
		--intervals;
	}
	int ans = 1;
	long long min_cost = p + intervals * (intervals + 1) / 2 * c;
	for(int i = 2; i <= n; ++i){
		cin >> p >> k >> c;
		intervals = q / k;
		if(q % k == 0){
			--intervals;
		}
		long long cost = p + intervals * (intervals + 1) / 2 * c;
		if(cost < min_cost){
			ans = i;
			min_cost = cost;
		}
	}
	cout << ans << ' ' << min_cost;
	return 0;
}
