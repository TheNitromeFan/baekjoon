#include <cstdio>
#include <vector>
#define MAX 1001

using namespace std;

int find_parent(vector<int> &parent, int x){
	if(parent[x] == x){
		return x;
	}else{
		parent[x] = find_parent(parent, parent[x]);
		return parent[x];
	}
}

void unite(vector<int> &parent, int x, int y){
	int px = find_parent(parent, x);
	int py = find_parent(parent, y);
	parent[py] = px;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	vector<int> parent(n * m);
	for(int k = 0; k < n * m; ++k){
		parent[k] = k;
	}
	int comps = n * m;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			int ni = i, nj = j;
			switch(map[i][j]){
				case 'D':
					++ni;
					break;
				case 'U':
					--ni;
					break;
				case 'R':
					++nj;
					break;
				case 'L':
					--nj;
					break;
			}
			int x = m * i + j;
			int nx = m * ni + nj;
			if(find_parent(parent, x) != find_parent(parent, nx)){
				--comps;
				unite(parent, x, nx);
			}
		}
	}
	printf("%d", comps);
	return 0;
}
