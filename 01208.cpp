#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void dfs_left(unordered_map<int, int> &ps, vector<int> &v, int n, int idx, int sum){
	if(idx == n / 2){
		++ps[sum];
		return;
	}
	dfs_left(ps, v, n, idx + 1, sum);
	dfs_left(ps, v, n, idx + 1, sum + v[idx]);
}

long long dfs_right(unordered_map<int, int> &ps, vector<int> &v, int n, int s, int idx, int sum){
	if(idx == n){
		return ps[s - sum];
	}
	return dfs_right(ps, v, n, s, idx + 1, sum) + dfs_right(ps, v, n, s, idx + 1, sum + v[idx]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, s;
	cin >> n >> s;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	unordered_map<int, int> psums;
	dfs_left(psums, v, n, 0, 0);
	long long ans = dfs_right(psums, v, n, s, n / 2, 0);
	if(s == 0){
		--ans;
	}
	cout << ans;
	return 0;
}
