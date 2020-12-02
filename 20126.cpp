#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int test(vector<pair<int, int>> &v, int n, int m, int s){
	if(m <= v[0].first){
		return 0;
	}
	for(int i = 0; i + 1 < n; ++i){
		if(v[i].second + m <= v[i + 1].first){
			return v[i].second;
		}
	}
	if(v[n - 1].second + m <= s){
		return v[n - 1].second;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, s;
	cin >> n >> m >> s;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
		v[i].second += v[i].first;
	}
	sort(v.begin(), v.end());
	cout << test(v, n, m, s);
	return 0;
}
