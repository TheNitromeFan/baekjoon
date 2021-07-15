#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 305
#define MAXV 1000000000

using namespace std;

int cache[MAXN][MAXN][2];

int dp(vector<int> &v, int n, int left, int right, int state, int rem){
	if(rem == 0){
		return 0;
	}else if(left > right){
		return MAXV;
	}
	if(cache[left][right][state] != -1){
		return cache[left][right][state];
	}
	cache[left][right][state] = MAXV;
	if(state){
		if(right != n){
			cache[left][right][state] = min(cache[left][right][state], dp(v, n, left, right + 1, 0, rem - 1) + rem * (v[right + 1] - v[left]));
		}
		if(left != 0){
			cache[left][right][state] = min(cache[left][right][state], dp(v, n, left - 1, right, 1, rem - 1) + rem * (v[left] - v[left - 1]));
		}
	}else{
		if(right != n){
			cache[left][right][state] = min(cache[left][right][state], dp(v, n, left, right + 1, 0, rem - 1) + rem * (v[right + 1] - v[right]));
		}
		if(left != 0){
			cache[left][right][state] = min(cache[left][right][state], dp(v, n, left - 1, right, 1, rem - 1) + rem * (v[right] - v[left - 1]));
		}
	}
	return cache[left][right][state];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	v.push_back(0);
	sort(v.begin(), v.end());
	int idx = lower_bound(v.begin(), v.end(), 0) - v.begin();
	int ans = 0;
	for(int i = 0; i <= n; ++i){
		memset(cache, -1, sizeof(cache));
		ans = max(ans, i * m - dp(v, n, idx, idx, 0, i));
	}
	cout << ans << '\n';
	return 0;
}
