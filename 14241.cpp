#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		pq.push(x);
	}
	long long ans = 0;
	while(pq.size() > 1){
		int x = pq.top();
		pq.pop();
		int y = pq.top();
		pq.pop();
		pq.push(x + y);
		ans += x * y;
	}
	cout << ans;
	return 0;
}
