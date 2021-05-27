#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int j = 0; j < m; ++j){
		cin >> b[j];
	}
	int ans = 0;
	for(int j = 0; j < m; ++j){
		int idx = j;
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			if(idx < m && b[idx] == a[i]){
				++idx;
				++cnt;
			}
		}
		if(ans < cnt){
			ans = cnt;
		}
	}
	cout << ans;
	return 0;
}
