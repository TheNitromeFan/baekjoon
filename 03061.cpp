#include <iostream>
#include <vector>

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
		int ans = 0;
		for(int j = 1; j <= n; ++j){
			for(int i = 0; i < n; ++i){
				if(v[i] == j){
					break;
				}else if(v[i] > j){
					++ans;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
