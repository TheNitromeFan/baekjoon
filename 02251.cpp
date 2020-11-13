#include <cstdio>
#include <queue>
#include <algorithm>
#define MAX (200 + 1)

void bfs(int a, int b, int c, bool ans[MAX]){
	std::queue<int> q;
	static bool visited[MAX][MAX][MAX] = {};
	q.push(0);
	q.push(0);
	q.push(c);
	ans[c] = true;
	visited[a][b][c] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int z = q.front();
		q.pop();
		if(x > 0){
			if(y < b){
				int pour = std::min(x, b - y);
				int nx = x - pour, ny = y + pour, nz = z;
				if(!visited[nx][ny][nz]){
					q.push(nx);
					q.push(ny);
					q.push(nz);
					if(nx == 0){
						ans[nz] = true;
					}
					visited[nx][ny][nz] = true;
				}
			}
			if(z < c){
				int pour = std::min(x, c - z);
				int nx = x - pour, ny = y, nz = z + pour;
				if(!visited[nx][ny][nz]){
					q.push(nx);
					q.push(ny);
					q.push(nz);
					if(nx == 0){
						ans[nz] = true;
					}
					visited[nx][ny][nz] = true;
				}
			}
		}
		if(y > 0){
			if(x < a){
				int pour = std::min(y, a - x);
				int nx = x + pour, ny = y - pour, nz = z;
				if(!visited[nx][ny][nz]){
					q.push(nx);
					q.push(ny);
					q.push(nz);
					if(nx == 0){
						ans[nz] = true;
					}
					visited[nx][ny][nz] = true;
				}
			}
			if(z < c){
				int pour = std::min(y, c - z);
				int nx = x, ny = y - pour, nz = z + pour;
				if(!visited[nx][ny][nz]){
					q.push(nx);
					q.push(ny);
					q.push(nz);
					if(nx == 0){
						ans[nz] = true;
					}
					visited[nx][ny][nz] = true;
				}
			}
		}
		if(z > 0){
			if(x < a){
				int pour = std::min(z, a - x);
				int nx = x + pour, ny = y, nz = z - pour;
				if(!visited[nx][ny][nz]){
					q.push(nx);
					q.push(ny);
					q.push(nz);
					if(nx == 0){
						ans[nz] = true;
					}
					visited[nx][ny][nz] = true;
				}
			}
			if(y < b){
				int pour = std::min(z, b - y);
				int nx = x, ny = y + pour, nz = z - pour;
				if(!visited[nx][ny][nz]){
					q.push(nx);
					q.push(ny);
					q.push(nz);
					if(nx == 0){
						ans[nz] = true;
					}
					visited[nx][ny][nz] = true;
				}
			}
		}
	}
}

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	bool ans[MAX] = {};
	bfs(a, b, c, ans);
	for(int i = 0; i <= c; ++i){
		if(ans[i]){
			printf("%d ", i);
		}
	}
	return 0;
}
