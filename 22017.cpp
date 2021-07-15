#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> v[i];
	}
	vector<int> psum(n + 1);
	for(int i = 1; i <= n; ++i){
		psum[i] = psum[i - 1] + v[i];
	}
	int ans = psum[n];
	for(int i = 1; i <= n; ++i){
		ans = min(ans, i - psum[i] + psum[n] - psum[i]);
	}
	cout << ans << '\n';
	return 0;
}
