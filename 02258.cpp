#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long m;
	cin >> n >> m;
	vector<pair<long long, long long>> v(n);
	for(int i = 0; i < n; ++i){
		long long w, p;
		cin >> w >> p;
		v[i] = make_pair(w, p);
	}
	sort(v.begin(), v.end(), [](pair<long long, long long> a, pair<long long, long long> b){
		return a.second < b.second || (a.second == b.second && a.first > b.first);
	});
	long long sum = 0;
	long long ans = 2000000000000000000LL;
	long long same = 0;
	for(int idx = 0; idx < n; ++idx){
		sum += v[idx].first;
		if(idx > 0 && v[idx].second == v[idx - 1].second){
			same += v[idx].second;
		}else{
			same = 0;
		}
		if(sum >= m){
			ans = min(ans, v[idx].second + same);
		}
	}
	if(ans < 2000000000000000000LL){
		cout << ans << '\n';
	}else{
		cout << -1 << '\n';
	}
	return 0;
}
