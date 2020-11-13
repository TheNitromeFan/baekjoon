#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#define MAX 100000

using namespace std;

bool traverse(map<int, vector<int>> &adj, map<int, int> &indegree){
	if(adj.size() == 0){
		return true;
	}
	queue<int> q;
	for(auto p : indegree){
		if(p.second == 0){
			q.push(p.first);
		}else if(p.second > 1){
			return false;
		}
	}
	if(q.size() != 1){
		return false;
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj[u]){
			--indegree[v];
			q.push(v);
		}
	}
	for(auto p : indegree){
		if(p.second != 0){
			return false;
		}
	}
	return true;
}

int main(){
	int test = 0;
	map<int, vector<int>> adj;
	map<int, int> indegree;
	while(true){
		++test;
		int u, v;
		adj.clear();
		indegree.clear();
		while(true){
			scanf("%d %d", &u, &v);
			if(u < 0 && v < 0){
				return 0;
			}else if(u == 0 && v == 0){
				break;
			}else{
				if(adj.find(u) == adj.end()){
					adj[u] = {v};
				}else{
					adj[u].push_back(v);
				}
				if(indegree.find(u) == indegree.end()){
					indegree[u] = 0;
				}
				if(indegree.find(v) == indegree.end()){
					indegree[v] = 1;
				}else{
					++indegree[v];
				}
			}
		}
		if(traverse(adj, indegree)){
			printf("Case %d is a tree.\n", test);
		}else{
			printf("Case %d is not a tree.\n", test);
		}
	}
}
