#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

int area(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	int cross = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
	return abs(cross);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for(int i = 0; i < n; ++i){
		cin >> p[i].first >> p[i].second;
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			for(int k = 0; k < j; ++k){
				double cmp = area(p[i], p[j], p[k]);
				if(ans < cmp){
					ans = cmp;
				}
			}
		}
	}
	cout << ans / 2;
	if(ans % 2 == 1){
		cout << ".5";
	}else{
		cout << ".0";
	}
	return 0;
}
