#include <iostream>
#include <string>
#define MAX ((int)'z' + 1)

using namespace std;

void floyd_warshall(bool adj[][MAX]){
	for(int k = 0; k < MAX; ++k){
		if(!((k >= 'A' && k <= 'Z') || (k >= 'a' && k <= 'z'))){
			continue;
		}
		for(int i = 0; i < MAX; ++i){
			if(!((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))){
				continue;
			}
			for(int j = 0; j < MAX; ++j){
				if(!((j >= 'A' && j <= 'Z') || (j >= 'a' && j <= 'z'))){
					continue;
				}
				if(adj[i][k] && adj[k][j]){
					adj[i][j] = true;
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	bool adj[MAX][MAX] = {};
	for(int v = 0; v < MAX; ++v){
		adj[v][v] = true;
	}
	for(int i = 0; i < n; ++i){
		getline(cin, line);
		char p = line[0], q = line[5];
		adj[p][q] = true;
	}
	floyd_warshall(adj);
	int cnt = 0;
	string ans;
	for(int u = 0; u < MAX; ++u){
		if(!((u >= 'A' && u <= 'Z') || (u >= 'a' && u <= 'z'))){
			continue;
		}
		for(int v = 0; v < MAX; ++v){
			if(!((v >= 'A' && v <= 'Z') || (v >= 'a' && v <= 'z'))){
				continue;
			}
			if(u != v && adj[u][v]){
				++cnt;
				ans += "\n";
				ans += (char)u;
				ans += " => ";
				ans += (char)v;
			}
		}
	}
	cout << cnt << ans;
	return 0;
}
