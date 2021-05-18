#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool all_marked(vector<bool> &balls, int left, int right){
	for(int i = left; i <= right; ++i){
		if(!balls[i]){
			return false;
		}
	}
	return true;
}

void mark(vector<bool> &balls, int left, int right){
	for(int i = left; i <= right; ++i){
		balls[i] = true;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<bool> balls(n + 1);
	vector<pair<int, int>> ops(m);
	for(int i = 0; i < m; ++i){
		cin >> ops[i].first >> ops[i].second;
	}
	reverse(ops.begin(), ops.end());
	long long ans = 1;
	for(pair<int, int> p : ops){
		int left = p.first, right = p.second;
		if(!all_marked(balls, left, right)){
			ans *= 2;
			mark(balls, left, right);
		}
	}
	cout << ans;
	return 0;
}
