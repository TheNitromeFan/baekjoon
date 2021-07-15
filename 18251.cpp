#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 270000

using namespace std;

vector<pair<int, int>> vec;

void dfs(int v[MAX], int n, int num, int depth, int &cnt){
	if(2 * num <= n){
		dfs(v, n, 2 * num, depth + 1, cnt);
	}
	v[num] = cnt;
	vec.push_back(make_pair(depth, cnt));
	++cnt;
	if(2 * num + 1 <= n){
		dfs(v, n, 2 * num + 1, depth + 1, cnt);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int cnt = 0;
	int v[MAX] = {};
	long long a[MAX] = {};
	dfs(v, n, 1, 0, cnt);
	for(int i = 1; i <= n; ++i){
		cin >> a[v[i]];
	}
	long long ans = -1000000001;
	for(int k = 0; k < n; ++k){
		ans = max(ans, a[k]);
	}
	if(ans <= 0){
		cout << ans << '\n';
		return 0;
	}
	ans = 0;
	for(int i = 0; i < 20; ++i){
		for(int j = 0; j <= i; ++j){
			long long cur_sum = 0, best_sum = 0;
			for(int k = 0; k < n; ++k){
				if(vec[k].first >= j && vec[k].first <= i){
					cur_sum = max(0LL, cur_sum + a[k]);
					best_sum = max(best_sum, cur_sum);
				}
			}
			ans = max(ans, best_sum);
		}
	}
	cout << ans << '\n';
	return 0;
}
