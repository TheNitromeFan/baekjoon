#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int count(vector<pair<int, int>> ocean, int width, int height, int lx, int ly){
	int ans = 0;
	for(pair<int, int> fish : ocean){
		if(fish.first >= lx && fish.first <= lx + width && fish.second >= ly && fish.second <= ly + height){
			++ans;
		}
	}
	return ans;
}

int main(){
	int n, l, m;
	cin >> n >> l >> m;
	vector<pair<int, int>> ocean;
	pair<int, int> fish;
	for(int i = 0; i < m; ++i){
		cin >> fish.first >> fish.second;
		ocean.push_back(fish);
	}
	int max = 0;
	for(int w = 1; w < l/2; ++w){
		int h = l/2 - w;
		for(pair<int, int> fish1 : ocean){
			for(pair<int, int> fish2 : ocean){
				int lx = fish1.first, ly = fish2.second;
				if(fish1.first > n-w){
					lx = n-w;
				}
				if(fish2.second > n-h){
					ly = n-h;
				}
				int cmp = count(ocean, w, h, lx, ly);
				if(cmp > max){
					max = cmp;
				}
			}
		}
	}
	cout << max << endl;
	return 0;
}
