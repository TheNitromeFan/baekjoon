#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Cmp{
	public:
		bool operator()(pair<int, int> a, pair<int, int> b){
			return a.first < b.first || (a.first == b.first && a.second > b.second);
		}
};

int main(){
	int n, len;
	cin >> n >> len;
	vector<pair<int, int>> puddles(n);
	for(int i = 0; i < n; ++i){
		int start, end;
		cin >> start >> end;
		puddles[i] = make_pair(start, end);
	}
	sort(puddles.begin(), puddles.end(), Cmp());
	long long ans = 0;
	int prev = -1;
	for(int i = 0; i < n; ++i){
		if(puddles[i].second < prev){
			continue;
		}
		if(puddles[i].first >= prev){
			int cnt = (puddles[i].second - puddles[i].first) / len;
			if((puddles[i].second - puddles[i].first) % len != 0){
				++cnt;
			}
			ans += cnt;
			prev = puddles[i].first + cnt * len;
		}else{
			int cnt = (puddles[i].second - prev) / len;
			if((puddles[i].second - prev) % len != 0){
				++cnt;
			}
			ans += cnt;
			prev = prev + cnt * len;
		}
	}
	cout << ans;
	return 0;
}
