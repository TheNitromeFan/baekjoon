#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int count(vector<pair<int, int>> &stars, int k, int lx, int ly){
	int ans = 0;
	for(pair<int, int> star : stars){
		if(star.first >= lx && star.first <= lx + k && star.second >= ly && star.second <= ly + k){
			++ans;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, len, k;
	cin >> n >> m >> len >> k;
	vector<pair<int, int>> stars(k);
	for(int i = 0; i < k; ++i){
		cin >> stars[i].first >> stars[i].second;
	}
	int max = 0;
	for(int i = 0; i < k; ++i){
		for(int j = 0; j < k; ++j){
			int lx = stars[i].first, ly = stars[j].second;
			if(stars[i].first > n - len){
				lx = n - len;
			}
			if(stars[j].second > m - len){
				ly = m - len;
			}
			int cmp = count(stars, len, lx, ly);
			if(cmp > max){
				max = cmp;
			}
		}
	}
	cout << k - max;
	return 0;
}
