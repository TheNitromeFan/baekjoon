#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int dist(pair<int, int> p1, pair<int, int> p2){
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int trail(vector<pair<int, int>> &v, pair<int, int> p){
	pair<int, int> tmp = p;
	int ret = 0;
	for(pair<int, int> x : v){
		ret += dist(x, p);
		p = x;
	}
	ret += dist(tmp, p);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int w, h;
		cin >> w >> h;
		pair<int, int> p0;
		cin >> p0.first >> p0.second;
		int n;
		cin >> n;
		vector<pair<int, int>> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i].first >> v[i].second;
		}
		sort(v.begin(), v.end());
		int ans = 1000000000;
		do{
			int cmp = trail(v, p0);
			if(ans > cmp){
				ans = cmp;
			}
		}while(next_permutation(v.begin(), v.end()));
		cout << "The shortest path has length " << ans << "\n";
	}
	return 0;
}
