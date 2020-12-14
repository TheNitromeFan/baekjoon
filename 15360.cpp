#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector<bool> lit(n + 1);
	for(int i = 0; i < m; ++i){
		int x;
		cin >> x;
		for(int j = x - k; j <= x + k; ++j){
			if(j >= 1 && j <= n){
				lit[j] = true;
			}
		}
	}
	int ans = 0;
	for(int j = 1; j <= n; ++j){
		if(!lit[j]){
			// cout << j << '\n';
			++ans;
			j += 2 * k;
		}
	}
	cout << ans;
	return 0;
}
