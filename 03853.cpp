#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <utility>

using namespace std;

void bfs(vector<vector<pair<int, int>>> &adj, vector<int> &keys, int start, int end){
	queue<pair<int, int>> q; // pos, key
	map<pair<int, int>, vector<int>> path;
	q.push(make_pair(start, -1));
	path[make_pair(start, -1)] = {start};
	if(keys[start] != -1){
		q.push(make_pair(start, keys[start]));
		path[make_pair(start, keys[start])] = {start};
	}
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		int pos = p.first;
		int key = p.second;
		printf("%d %d\n", pos, key);
		if(pos == end){
			vector<int> ans = path[p];
			printf("%llu: ", ans.size() - 1);
			for(int v : ans){
				printf("%d ", v);
			}
			printf("\n");
			return;
		}
		for(pair<int, int> np : adj[pos]){
			int npos = np.first;
			int lock = np.second;
			if(lock != -1 && key == lock && path.find(make_pair(npos, -1)) == path.end()){
				np.second = -1;
				for(pair<int, int> tmp : adj[npos]){
					if(tmp.first == pos){
						tmp.second = -1;
						break;
					}
				}
				q.push(make_pair(npos, -1));
				path[make_pair(npos, -1)] = path[p];
				path[make_pair(npos, -1)].push_back(npos);
				if(keys[npos] != -1){
					q.push(make_pair(npos, keys[npos]));
					path[make_pair(npos, keys[npos])] = path[p];
					path[make_pair(npos, keys[npos])].push_back(npos);
				}
			}else if(lock == -1 && path.find(make_pair(npos, key)) == path.end()){
				q.push(make_pair(npos, key));
				path[make_pair(npos, key)] = path[p];
				path[make_pair(npos, key)].push_back(npos);
				if(key == -1 && keys[npos] != -1){
					q.push(make_pair(npos, keys[npos]));
					path[make_pair(npos, keys[npos])] = path[p];
					path[make_pair(npos, keys[npos])].push_back(npos);
				}
			}
		}
	}
	printf("Impossible\n");
}

int main(){
	while(true){
		int v, c, x, y;
		scanf("%d %d %d %d", &v, &c, &x, &y);
		if(v == 0 && c == 0 && x == 0 && y == 0){
			break;
		}
		vector<int> keys(v, -1); // room i has lock number locks[i]
		for(int i = 0; i < c; ++i){
			int room;
			scanf("%d", &room);
			keys[room] = i;
		}
		vector<vector<pair<int, int>>> adj;
		adj.resize(v);
		for(int j = 1; j < v; ++j){
			int a, b, lock;
			scanf("%d %d %d", &a, &b, &lock);
			adj[a].push_back(make_pair(b, lock));
			adj[b].push_back(make_pair(a, lock));
		}
		bfs(adj, keys, x, y);
	}
	return 0;
}
