#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void copy_array(int src[][5], int dest[][5]){
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			dest[i][j] = src[i][j];
		}
	}
}

void rotate_90(int a[][5]){
	int b[5][5];
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			b[i][j] = a[j][4 - i];
		}
	}
	copy_array(b, a);
}

int bfs(int cube[][5][5], int dx[6], int dy[6], int dz[6]){
	int dist[5][5][5];
	queue<int> q;
	bool visited[5][5][5] = {};
	dist[0][0][0] = 0;
	q.push(0);
	q.push(0);
	q.push(0);
	visited[0][0][0] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int z = q.front();
		q.pop();
		if(x == 4 && y == 4 && z == 4){
			return dist[4][4][4];
		}
		for(int i = 0; i < 6; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && nz >= 0 && nz < 5 && cube[nx][ny][nz] && !visited[nx][ny][nz]){
				dist[nx][ny][nz] = dist[x][y][z] + 1;
				q.push(nx);
				q.push(ny);
				q.push(nz);
				visited[nx][ny][nz] = true;
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int boards[5][5][5];
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			for(int k = 0; k < 5; ++k){
				cin >> boards[i][j][k];
			}
		}
	}
	int cube[5][5][5];
	vector<int> perm = {0, 1, 2, 3, 4};
	int dx[6] = {1, -1, 0, 0, 0, 0};
	int dy[6] = {0, 0, 1, -1, 0, 0};
	int dz[6] = {0, 0, 0, 0, 1, -1};
	int min_path = -1;
	do{
		for(int i = 0; i < 5; ++i){
			copy_array(boards[perm[i]], cube[i]);
		}
		for(int a0 = 0; a0 < 4; ++a0){
			for(int a1 = 0; a1 < 4; ++a1){
				for(int a2 = 0; a2 < 4; ++a2){
					for(int a3 = 0; a3 < 4; ++a3){
						for(int a4 = 0; a4 < 4; ++a4){
							if(cube[0][0][0]){
								int cmp = bfs(cube, dx, dy, dz);
								if(cmp != -1 && (min_path == -1 || min_path > cmp)){
									min_path = cmp;
								}
							}
							rotate_90(cube[4]);
						}
						rotate_90(cube[3]);
					}
					rotate_90(cube[2]);
				}
				rotate_90(cube[1]);
			}
			rotate_90(cube[0]);
		}
	}while(next_permutation(perm.begin(), perm.end()));
	cout << min_path;
	return 0;
}
