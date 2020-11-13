#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

char map[12][7];
bool visited[12][6];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bubble_count;

vector<pair<int, int>> cluster, to_remove;

void dfs(int x, int y, int score){
	cluster.push_back(make_pair(x, y));
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < 12 && ny >= 0 && ny < 6 && map[nx][ny] == map[x][y] && !visited[nx][ny]){
			++bubble_count;
			// printf("%d %d\n", nx, ny);
			visited[nx][ny] = true;
			dfs(nx, ny, score+1);
		}
	}
}

int main(){
	for(int i = 0; i < 12; ++i){
		scanf("%s", map[i]);
	}
	bool cluster_found;
	int combo = 0;
	while(true){
		cluster_found = false;
		memset(visited, false, sizeof(visited));
		to_remove.clear();
		for(int i = 0; i < 12; ++i){
			for(int j = 0; j < 6; ++j){
				if(map[i][j] != '.' && !visited[i][j]){
					bubble_count = 1;
					visited[i][j] = true;
					dfs(i, j, 1);
					if(bubble_count >= 4){
						cluster_found = true;
						for(auto p : cluster){
							to_remove.push_back(p);
						}
					}
					cluster.clear();
				}
			}
		}
		if(cluster_found){
			++combo;
		}else{
			break;
		}
		for(auto p : to_remove){
			int x = p.first, y = p.second;
			map[x][y] = '.';
		}
		for(int i = 10; i >= 0; --i){
			for(int j = 0; j < 6; ++j){
				for(int k = 11; k > i; --k){
					if(map[i][j] != '.' && map[k][j] == '.'){
						map[k][j] = map[i][j];
						map[i][j] = '.';
						break;
					}
				}
			}
		}
		/*
		printf("-------------\n");
		for(int i = 0; i < 12; ++i){
			for(int j = 0; j < 6; ++j){
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
		*/
	}
	printf("%d", combo);
	return 0;
}
