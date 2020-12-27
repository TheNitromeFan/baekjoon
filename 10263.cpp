#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int ans = n;
	for(int x = 0; x < n; ++x){
		if(ans > x + v[n - 1 - x]){
			ans = x + v[n - 1 - x];
		}
	}
	cout << ans;
	return 0;
}
