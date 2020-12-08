#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		long long a[1000000];
		for(int j = 0; j < n; ++j){
			cin >> a[j];
		}
		long long ans = 0;
		int max = -1;
		for(int idx = n - 1; idx >= 0; --idx){
			if(max < a[idx]){
				max = a[idx];
			}
			ans += max - a[idx];
			// cout << ans << '\n';
		}
		cout << ans << '\n';
	}
	return 0;
}
