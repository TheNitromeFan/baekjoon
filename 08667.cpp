#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	int psum = 0;
	int ans = 0;
	int idx = 0;
	while(idx < n){
		int start = idx;
		while(idx < n && v[idx] == v[start]){
			++idx;
		}
		ans = max(ans, idx - start + min(psum, k));
		psum += idx - start;
	}
	cout << ans;
	return 0;
}
