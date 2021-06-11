#include <cstdio>
#include <vector>

using namespace std;

bool dfs(char board[][4], bool visited[][3], int dx[4], int dy[4], int n, int m, int x, int y, int cur, vector<int> &ans){
	if(m == 0){
		return cur == n;
	}
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!(nx >= 0 && nx < 3 && ny >= 0 && ny < 3 && !visited[nx][ny])){
			continue;
		}
		visited[nx][ny] = true;
		ans.push_back(nx);
		ans.push_back(ny);
		for(int j = 0; j < 4; ++j){
			int nnx = nx + dx[j];
			int nny = ny + dy[j];
			if(!(nnx >= 0 && nnx < 3 && nny >= 0 && nny < 3 && !visited[nnx][nny])){
				continue;
			}
			visited[nnx][nny] = true;
			ans.push_back(nnx);
			ans.push_back(nny);
			int ncur = cur;
			if(board[nx][ny] == '+'){
				ncur += board[nnx][nny] - '0';
			}else{
				ncur -= board[nnx][nny] - '0';
			}
			if(dfs(board, visited, dx, dy, n, m - 1, nnx, nny, ncur, ans)){
				return true;
			}
			visited[nnx][nny] = false;
			ans.pop_back();
			ans.pop_back();
		}
		visited[nx][ny] = false;
		ans.pop_back();
		ans.pop_back();
	}
	return false;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char board[3][4];
	for(int i = 0; i < 3; ++i){
		scanf("%s", board[i]);
	}
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	bool visited[3][3] = {};
	vector<int> ans;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if((i + j) % 2 == 0){
				visited[i][j] = true;
				ans.push_back(i);
				ans.push_back(j);
				if(dfs(board, visited, dx, dy, n, m - 1, i, j, board[i][j] - '0', ans)){
					printf("1\n");
					for(unsigned idx = 0; idx < ans.size(); idx += 2){
						printf("%d %d\n", ans[idx], ans[idx + 1]);
					}
					return 0;
				}
				visited[i][j] = false;
				ans.pop_back();
				ans.pop_back();
			}
		}
	}
	printf("0\n");
	return 0;
}
