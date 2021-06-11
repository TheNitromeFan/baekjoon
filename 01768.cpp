#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool symmetry(vector<pair<int, int>> &p, int n){
	sort(p.begin(), p.end());
	for(int i = 1; i < (n + 1) / 2; ++i){
		if(!(p[i].first + p[n - 1 - i].first == p[0].first + p[n - 1].first
		&& p[i].second + p[n - 1 - i].second == p[0].second + p[n - 1].second)){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<pair<int, int>> p(n);
		for(int i = 0; i < n; ++i){
			cin >> p[i].first >> p[i].second;
		}
		cout << (symmetry(p, n) ? "yes\n" : "no\n");
	}
	return 0;
}
