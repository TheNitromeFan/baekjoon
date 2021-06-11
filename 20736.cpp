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
	int ans = v[0] + v[n - 2];
	for(int i = 1; i < n; ++i){
		ans = min(ans, v[i] + v[(i + n - 2) % n]);
	}
	cout << ans;
	return 0;
}
