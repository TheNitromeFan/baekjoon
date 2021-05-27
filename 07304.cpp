#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i];
		}
		sort(v.begin(), v.end(), greater<int>());
		int ans = 0;
		for(int i = 0; i < n; ++i){
			ans = max(ans, v[i] * (i + 1));
		}
		cout << ans << '\n';
	}
	return 0;
}
