#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		int ans = 0;
		for(int i = 0; i < n; ++i){
			int left = 0, right = 0;
			for(int j = 0; j < n; ++j){
				if(a[j] > a[i]){
					if(j < i){
						++left;
					}else{
						++right;
					}
				}
			}
			ans += min(left, right);
		}
		cout << "Case #" << a0 << ": " << ans << "\n";
	}
	return 0;
}
