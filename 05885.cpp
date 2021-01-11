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
	vector<pair<int, int>> lands(n);
	for(int i = 0; i < n; ++i){
		cin >> lands[i].second;
		lands[i].first = i;
	}
	vector<bool> underwater(n);
	sort(lands.begin(), lands.end(), [](pair<int, int> a, pair<int, int> b){
		return a.second < b.second;
	});
	int numIslands = 1, maxIslands = 1;
	for(int i = 0; i < n; ++i){
		int x = lands[i].first;
		underwater[x] = true;
		bool landToLeft = (x > 0 && !underwater[x - 1]);
		bool landToRight = (x < n - 1 && !underwater[x + 1]);
		if(landToLeft && landToRight){
			++numIslands;
		}else if(!landToLeft && !landToRight){
			--numIslands;
		}
		if((i == n - 1 || lands[i + 1].second > lands[i].second) && numIslands > maxIslands){
			maxIslands = numIslands;
		}
	}
	cout << maxIslands;
	return 0;
}
