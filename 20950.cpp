#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define MAXN 30

using namespace std;

int dist(int a[3], int b[3]){
	int ret = 0;
	for(int j = 0; j < 3; ++j){
		ret += abs(a[j] - b[j]);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int rgb[MAXN][3];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 3; ++j){
			cin >> rgb[i][j];
		}
	}
	int target[3];
	for(int j = 0; j < 3; ++j){
		cin >> target[j];
	}
	int ans = 100000;
	for(int colors = 2; colors <= min(n, 7); ++colors){
		vector<bool> bitmask(colors, true);
		bitmask.resize(n);
		do{
			int color[3] = {};
			for(int i = 0; i < n; ++i){
				if(bitmask[i]){
					for(int j = 0; j < 3; ++j){
						color[j] += rgb[i][j];
					}
				}
			}
			for(int j = 0; j < 3; ++j){
				color[j] /= colors;
			}
			ans = min(ans, dist(color, target));
		}while(prev_permutation(bitmask.begin(), bitmask.end()));
	}
	cout << ans << '\n';
	return 0;
}
