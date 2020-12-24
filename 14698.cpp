#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define MOD 1000000007

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for(int j = 0; j < n; ++j){
			long long x;
			cin >> x;
			pq.push(x);
		}
		long long ans = 1;
		while(pq.size() > 1){
			long long x = pq.top();
			pq.pop();
			long long y = pq.top();
			pq.pop();
			long long prod = x * y;
			ans *= prod;
			pq.push(prod);
			ans %= MOD;
		}
		cout << ans << "\n";
	}
	return 0;
}
