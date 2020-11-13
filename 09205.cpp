#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#define MAX 1000

using namespace std;

int dist(pair<int, int> a, pair<int, int> b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

bool dfs(vector<pair<int, int>> &stores, vector<bool> &visited, pair<int, int> &start, pair<int, int> &dest){
	if(dist(start, dest) <= MAX){
		return true;
	}
	for(unsigned i = 0; i < stores.size(); ++i){
		if(visited[i]){
			continue;
		}
		if(dist(start, stores[i]) <= MAX){
			visited[i] = true;
			if(dfs(stores, visited, stores[i], dest)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		pair<int, int> home, berg;
		vector<pair<int, int>> stores;
		stores.resize(n);
		scanf("%d %d", &home.first, &home.second);
		for(int j = 0; j < n; ++j){
			scanf("%d %d", &stores[j].first, &stores[j].second);
		}
		scanf("%d %d", &berg.first, &berg.second);
		vector<bool> visited(n, false);
		if(dfs(stores, visited, home, berg)){
			printf("happy\n");
		}else{
			printf("sad\n");
		}
	}
	return 0;
}
