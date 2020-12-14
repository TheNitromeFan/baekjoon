#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		vector<int> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int ans = 1000000000;
		for(int i = 0; i + 1 < n; ++i){
			ans = min(ans, v[i + 1] - v[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}
