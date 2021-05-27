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
	int ans = 0;
	for(int i = n - 1; i > 0; --i){
		if(v[0] != v[i]){
			ans = i;
			break;
		}
	}
	for(int i = 0; i < n - 1; ++i){
		if(v[n - 1] != v[i]){
			ans = max(ans, n - 1 - i);
			break;
		}
	}
	cout << ans;
	return 0;
}
