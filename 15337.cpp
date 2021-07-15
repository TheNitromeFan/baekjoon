#include <iostream>
#include <algorithm>
#define MAXN 200005

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int start[MAXN] = {}, end[MAXN] = {};
	int sum[MAXN] = {};
	int left[MAXN] = {}, right[MAXN] = {};
	for(int i = 1; i <= n; ++i){
		int x, y;
		cin >> x >> y;
		++start[x];
		++end[y];
		++sum[x];
		--sum[y];
		left[i] = x;
		right[i] = y;
	}
	for(int j = 1; j < MAXN; ++j){
		start[j] += start[j - 1];
		end[j] += end[j - 1];
		sum[j] += sum[j - 1];
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		ans = max(ans, start[right[i] - 1] - end[left[i]]);
	}
	cout << ans << ' ';
	ans = 0;
	for(int j = 1; j < MAXN; ++j){
		ans = max(ans, sum[j]);
	}
	cout << ans << '\n';
	return 0;
}
