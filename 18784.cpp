#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define MOD 1000000007
#define OFFSET 10000
#define MAXN (100000 + 5)
#define MAXRANGE (2 * 10000 + 1)

using namespace std;

void check(vector<pair<int, int>> t[MAXRANGE], vector<int> sum[MAXN]){
	for(int i = 0; i < MAXRANGE; ++i){
		if(t[i].empty()){
			continue;
		}
		sort(t[i].begin(), t[i].end());
		long long cur = 0;
		for(int j = 0; j < (int)t[i].size(); ++j){
			cur += t[i][j].first - t[i][0].first;
			cur %= MOD;
		}
		sum[t[i][0].second].push_back(cur);
		for(int j = 1; j < (int)t[i].size(); ++j){
			cur += (2 * j - (int)t[i].size()) * (t[i][j].first - t[i][j - 1].first);
			cur %= MOD;
			sum[t[i][j].second].push_back(cur);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> points(n);
	for(int i = 0; i < n; ++i){
		cin >> points[i].first >> points[i].second;
	}
	vector<pair<int, int>> t[MAXRANGE];
	vector<int> sum[MAXN];
	for(int i = 0; i < MAXRANGE; ++i){
		t[i].clear();
	}
	for(int i = 0; i < n; ++i){
		int x = points[i].first, y = points[i].second;
		t[x + OFFSET].push_back(make_pair(y, i));
	}
	check(t, sum);
	for(int i = 0; i < MAXRANGE; ++i){
		t[i].clear();
	}
	for(int i = 0; i < n; ++i){
		int x = points[i].first, y = points[i].second;
		t[y + OFFSET].push_back(make_pair(x, i));
	}
	check(t, sum);
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		ans += (long long)sum[i][0] * sum[i][1];
		ans %= MOD;
	}
	/*
	for(int i = 0; i < n; ++i){
		cout << points[i].first << ' ' << points[i].second << '\n';
	}
	*/
	cout << ans;
	return 0;
}
