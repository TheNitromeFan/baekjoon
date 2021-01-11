#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> en(n), ex(m);
	for(int i = 0; i < n; ++i){
		cin >> en[i];
	}
	for(int j = 0; j < m; ++j){
		cin >> ex[j];
	}
	map<int, int> cnt;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			int diff = ex[j] - en[i];
			if(diff >= 0){
				++cnt[diff];
				if(cnt[diff] > cnt[ans] || (cnt[diff] == cnt[ans] && diff < ans)){
					ans = diff;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
