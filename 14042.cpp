#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q, n;
	cin >> q >> n;
	vector<int> d(n), p(n);
	for(int i = 0; i < n; ++i){
		cin >> d[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> p[i];
	}
	sort(d.begin(), d.end());
	if(q == 1){
		sort(p.begin(), p.end());
	}else{
		sort(p.begin(), p.end(), greater<int>());
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans += max(d[i], p[i]);
	}
	cout << ans;
	return 0;
}
