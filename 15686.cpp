#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#define MAX 50

using namespace std;

int dist(pair<int, int> p, pair<int, int> q){
	return abs(p.first - q.first) + abs(p.second - q.second);
}

int nearest_chicken(vector<pair<int, int>> chicken, string bitmask, pair<int, int> p, int n){
	int ret = MAX * MAX * MAX;
	for(unsigned i = 0; i < chicken.size(); ++i){
		if(bitmask[i]){
			int cmp = dist(chicken[i], p);
			if(cmp < ret){
				ret = cmp;
			}
		}
	}
	return ret;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int city[MAX][MAX];
	vector<pair<int, int>> chicken;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &city[i][j]);
			if(city[i][j] == 2){
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	string bitmask(m, 1);
	bitmask.resize(chicken.size(), 0);
	int ans = MAX * MAX * MAX;
	do{
		int cmp = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(city[i][j] == 1){
					cmp += nearest_chicken(chicken, bitmask, make_pair(i, j), n);
				}
			}
		}
		if(ans > cmp){
			ans = cmp;
		}
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
	printf("%d", ans);
	return 0;
}
