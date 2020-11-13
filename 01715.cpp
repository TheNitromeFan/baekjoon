#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main(){
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		pq.push(x);
	}
	int ans = 0;
	for(int i = 1; i < n; ++i){
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		ans += a + b;
		pq.push(a + b);
	}
	cout << ans;
	return 0;
}
