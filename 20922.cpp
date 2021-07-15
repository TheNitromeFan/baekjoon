#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	int i = 0, j = 0;
	vector<int> cnt(100001);
	while(j < n){
		if(cnt[v[j]] == k){
			break;
		}
		++cnt[v[j]];
		++j;
	}
	int ans = j;
	while(j < n){
		int x = v[j];
		++cnt[x];
		++j;
		while(cnt[x] > k){
			--cnt[v[i]];
			++i;
		}
		ans = max(ans, j - i);
	}
	cout << ans << '\n';
	return 0;
}
