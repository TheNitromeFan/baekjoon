#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> t(n);
	for(int i = 0; i < n; ++i){
		cin >> t[i];
	}
	sort(t.begin(), t.end());
	long long ans = 0;
	if(n % 2 == 1){
		ans = max(ans, t.back());
		--n;
	}
	for(int i = 0, j = n - 1; i < j; ++i, --j){
		ans = max(ans, t[i] + t[j]);
	}
	cout << ans;
	return 0;
}
