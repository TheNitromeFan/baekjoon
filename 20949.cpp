#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, long long>> v(n);
	for(int i = 0; i < n; ++i){
		long long wi, hi;
		cin >> wi >> hi;
		v[i] = make_pair(i + 1, wi * wi + hi * hi);
	}
	sort(v.begin(), v.end(), [](pair<int, long long> a, pair<int, long long> b){
		return a.second > b.second || (a.second == b.second && a.first < b.first);
	});
	for(int i = 0; i < n; ++i){
		cout << v[i].first << '\n';
	}
	return 0;
}
