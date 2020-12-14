#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> hq(n), lq(m);
	for(int i = 0; i < n; ++i){
		cin >> hq[i];
	}
	for(int j = 0; j < m; ++j){
		cin >> lq[j];
	}
	sort(hq.begin(), hq.end(), greater<int>());
	sort(lq.begin(), lq.end(), greater<int>());
	int ans = 0;
	int j = 0;
	for(int i = 0; i < n; ++i){
		++ans;
		while(j < m && lq[j] >= hq[i]){
			++j;
		}
		if(j < m){
			++ans;
			++j;
		}
	}
	cout << ans;
	return 0;
}
