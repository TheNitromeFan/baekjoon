#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned n, k;
	cin >> n >> k;
	vector<int> v(6);
	for(unsigned i = 0; i < n; ++i){
		unsigned x;
		cin >> x;
		--x;
		++v[x];
	}
	sort(v.begin(), v.end(), greater<int>());
	while(v.back() == 0){
		v.pop_back();
	}
	if(v.size() <= k){
		cout << k - v.size();
		return 0;
	}
	int ans = 0;
	while(v.size() > k){
		ans += v.back();
		v.pop_back();
	}
	cout << ans;
	return 0;
}
