#include <cstdio>
#include <vector>

using namespace std;

vector<int> edges[1001];

int color[1001];

void check(int u, bool& possible){ // DFS
	for(int v : edges[u]){
		if(color[v] == 0){
			color[v] = 3 - color[u];
			check(v, possible);
		}else if(color[v] == color[u]){
			possible = false;
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; ++i){
			edges[i].clear();
			color[i] = 0;
		}
		for(int e = 0; e < m; ++e){
			int u, v;
			scanf("%d %d", &u, &v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		bool possible = true;
		for(int u = 1; u <= n; ++u){
			if(color[u] == 0){
				color[u] = 1;
				check(u, possible);
			}
		}
		if(possible){
			printf("possible");
		}else{
			printf("impossible");
		}
		printf("\n");
	}
	return 0;
}
