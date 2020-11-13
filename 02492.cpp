#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int count(vector<pair<int, int>> gems, int k, int lx, int ly){
	int ans = 0;
	for(pair<int, int> gem : gems){
		if(gem.first >= lx && gem.first <= lx + k && gem.second >= ly && gem.second <= ly + k){
			++ans;
		}
	}
	return ans;
}

int main(){
	int n, m, t, k;
	cin >> n >> m >> t >> k;
	vector<pair<int, int>> gems;
	pair<int, int> gem;
	for(int i = 0; i < t; ++i){
		cin >> gem.first >> gem.second;
		gems.push_back(gem);
	}
	int max = 0, x = 0, y = 0;
	for(int i = 0; i < t; ++i){
		for(int j = 0; j < t; ++j){
			int lx = gems[i].first, ly = gems[j].second;
			if(gems[i].first > n-k){
				lx = n-k;
			}
			if(gems[j].second > m-k){
				ly = m-k;
			}
			int cmp = count(gems, k, lx, ly);
			if(cmp > max){
				max = cmp;
				x = lx;
				y = ly + k;
			}
		}
	}
	cout << x << ' ' << y << '\n' << max << endl;
	return 0;
}
