#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n, m;
		cin >> n >> m;
		if(n == 0 && m == 0){
			break;
		}
		vector<int> cnt(n + 1);
		for(int i = 0; i < m; ++i){
			int t;
			cin >> t;
			++cnt[t];
		}
		int ans = 0;
		for(int j = 1; j <= n; ++j){
			if(cnt[j] > 1){
				++ans;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
