#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int p, n;
	cin >> p >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int psum = 0;
	int idx = 0;
	while(idx < n){
		if(psum + v[idx] >= p){
			break;
		}
		psum += v[idx];
		++idx;
	}
	sort(v.begin(), v.begin() + idx, greater<int>());
	int time = p - 1 - psum;
	long long ans = 0;
	for(int i = 0; i < idx; ++i){
		time += v[i];
		ans += time;
	}
	cout << idx << ' ' << ans << '\n';
	return 0;
}
