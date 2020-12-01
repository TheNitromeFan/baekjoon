#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	priority_queue<long long, vector<long long>, greater<long long>> cards;
	for(int i = 0; i < n; ++i){
		long long x;
		cin >> x;
		cards.push(x);
	}
	for(int j = 0; j < m; ++j){
		long long x = cards.top();
		cards.pop();
		long long y = cards.top();
		cards.pop();
		cards.push(x + y);
		cards.push(x + y);
	}
	long long ans = 0;
	while(!cards.empty()){
		ans += cards.top();
		cards.pop();
	}
	cout << ans;
	return 0;
}
