#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int k;
		cin >> k;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for(int i = 0; i < k; ++i){
			long long x;
			cin >> x;
			pq.push(x);
		}
		long long ans = 0;
		while(pq.size() > 1){
			long long x = pq.top();
			pq.pop();
			long long y = pq.top();
			pq.pop();
			ans += x + y;
			pq.push(x + y);
		}
		cout << ans << '\n';
	}
	return 0;
}
