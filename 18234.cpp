#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	cin >> n >> t;
	vector<pair<long long, long long>> carrots(n);
	for(int i = 0; i < n; ++i){
		cin >> carrots[i].first >> carrots[i].second;
	}
	sort(carrots.begin(), carrots.end(), [](pair<long long, long long> a, pair<long long, long long> b){
		return a.second < b.second;
	});
	long long sum = 0;
	for(int i = 0; i < n; ++i){
		sum += carrots[i].first + carrots[i].second * (t - n + i);
	}
	cout << sum;
	return 0;
}
