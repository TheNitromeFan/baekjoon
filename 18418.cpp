#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<long long, long long>> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	long long time = max(v[n - 1].first, v[n - 1].second);
	for(int i = n - 2; i >= 0; --i){
		time += v[i + 1].first - v[i].first;
		time = max(time, v[i].second);
	}
	time += v[0].first;
	cout << time;
	return 0;
}
