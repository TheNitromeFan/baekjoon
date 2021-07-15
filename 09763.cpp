#include <iostream>
#include <cstdlib>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int dist(tuple<int, int, int> a, tuple<int, int, int> b){
	return abs(get<0>(a) - get<0>(b)) + abs(get<1>(a) - get<1>(b)) + abs(get<2>(a) - get<2>(b));
}

void insert_dist(vector<int> &v, int x){
	if(v.size() == 2){
		if(x < v[0]){
			v[1] = v[0];
			v[0] = x;
		}else if(x < v[1]){
			v[1] = x;
		}
	}else if(v.size() == 1){
		if(x < v[0]){
			v.push_back(v[0]);
			v[0] = x;
		}else{
			v.push_back(x);
		}
	}else{
		v.push_back(x);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<tuple<int, int, int>> v(n);
	for(int i = 0; i < n; ++i){
		int x, y, z;
		cin >> x >> y >> z;
		v[i] = make_tuple(x, y, z);
	}
	vector<vector<int>> d(n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			int di = dist(v[j], v[i]);
			insert_dist(d[j], di);
			insert_dist(d[i], di);
		}
	}
	int ans = 1000000000;
	for(int i = 0; i < n; ++i){
		ans = min(ans, d[i][0] + d[i][1]);
	}
	cout << ans << '\n';
	return 0;
}
