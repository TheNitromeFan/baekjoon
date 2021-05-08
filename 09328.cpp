#include <cstdio>
#include <queue>
#include <vector>
#define MAX 101

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int documents(char map[][MAX], vector<bool> &keys, int h, int w){
	queue<int> q;
	vector<vector<int>> lockx(26), locky(26);
	bool visited[MAX][MAX] = {};
	int ret = 0;
	for(int j = 0; j < w; ++j){
		if(visited[0][j]){
			continue;
		}
		if(map[0][j] == '$'){
			++ret;
			q.push(0);
			q.push(j);
			visited[0][j] = true;
		}else if(map[0][j] == '.'){
			q.push(0);
			q.push(j);
			visited[0][j] = true;
		}else if(map[0][j] >= 'A' && map[0][j] <= 'Z'){
			if(keys[map[0][j] - 'A']){
				q.push(0);
				q.push(j);
				visited[0][j] = true;
			}else{
				lockx[map[0][j] - 'A'].push_back(0);
				locky[map[0][j] - 'A'].push_back(j);
			}
		}else if(map[0][j] >= 'a' && map[0][j] <= 'z'){
			keys[map[0][j] - 'a'] = true;
			for(unsigned idx = 0; idx < lockx[map[0][j] - 'a'].size(); ++idx){
				int lx = lockx[map[0][j] - 'a'][idx], ly = locky[map[0][j] - 'a'][idx];
				if(!visited[lx][ly]){
					q.push(lx);
					q.push(ly);
					visited[lx][ly] = true;
				}
			}
			q.push(0);
			q.push(j);
			visited[0][j] = true;
		}
		if(visited[h - 1][j]){
			continue;
		}
		if(map[h - 1][j] == '$'){
			++ret;
			q.push(h - 1);
			q.push(j);
			visited[h - 1][j] = true;
		}else if(map[h - 1][j] == '.'){
			q.push(h - 1);
			q.push(j);
			visited[h - 1][j] = true;
		}else if(map[h - 1][j] >= 'A' && map[h - 1][j] <= 'Z'){
			if(keys[map[h - 1][j] - 'A']){
				q.push(h - 1);
				q.push(j);
				visited[h - 1][j] = true;
			}else{
				lockx[map[h - 1][j] - 'A'].push_back(h - 1);
				locky[map[h - 1][j] - 'A'].push_back(j);
			}
		}else if(map[h - 1][j] >= 'a' && map[h - 1][j] <= 'z'){
			keys[map[h - 1][j] - 'a'] = true;
			for(unsigned idx = 0; idx < lockx[map[h - 1][j] - 'a'].size(); ++idx){
				int lx = lockx[map[h - 1][j] - 'a'][idx], ly = locky[map[h - 1][j] - 'a'][idx];
				if(!visited[lx][ly]){
					q.push(lx);
					q.push(ly);
					visited[lx][ly] = true;
				}
			}
			q.push(h - 1);
			q.push(j);
			visited[h - 1][j] = true;
		}
	}
	for(int i = 0; i < h; ++i){
		if(visited[i][0]){
			continue;
		}
		if(map[i][0] == '$'){
			++ret;
			q.push(i);
			q.push(0);
			visited[i][0] = true;
		}else if(map[i][0] == '.'){
			q.push(i);
			q.push(0);
			visited[i][0] = true;
		}else if(map[i][0] >= 'A' && map[i][0] <= 'Z'){
			if(keys[map[i][0] - 'A']){
				q.push(i);
				q.push(0);
				visited[i][0] = true;
			}else{
				lockx[map[i][0] - 'A'].push_back(i);
				locky[map[i][0] - 'A'].push_back(0);
			}
		}else if(map[i][0] >= 'a' && map[i][0] <= 'z'){
			keys[map[i][0] - 'a'] = true;
			for(unsigned idx = 0; idx < lockx[map[i][0] - 'a'].size(); ++idx){
				int lx = lockx[map[i][0] - 'a'][idx], ly = locky[map[i][0] - 'a'][idx];
				if(!visited[lx][ly]){
					q.push(lx);
					q.push(ly);
					visited[lx][ly] = true;
				}
			}
			q.push(i);
			q.push(0);
			visited[i][0] = true;
		}
		if(visited[i][w - 1]){
			continue;
		}
		if(map[i][w - 1] == '$'){
			++ret;
			q.push(i);
			q.push(w - 1);
			visited[i][w - 1] = true;
		}else if(map[i][w - 1] == '.'){
			q.push(i);
			q.push(w - 1);
			visited[i][w - 1] = true;
		}else if(map[i][w - 1] >= 'A' && map[i][w - 1] <= 'Z'){
			if(keys[map[i][w - 1] - 'A']){
				q.push(i);
				q.push(w - 1);
				visited[i][w - 1] = true;
			}else{
				lockx[map[i][w - 1] - 'A'].push_back(i);
				locky[map[i][w - 1] - 'A'].push_back(w - 1);
			}
		}else if(map[i][w - 1] >= 'a' && map[i][w - 1] <= 'z'){
			keys[map[i][w - 1] - 'a'] = true;
			for(unsigned idx = 0; idx < lockx[map[i][w - 1] - 'a'].size(); ++idx){
				int lx = lockx[map[i][w - 1] - 'a'][idx], ly = locky[map[i][w - 1] - 'a'][idx];
				if(!visited[lx][ly]){
					q.push(lx);
					q.push(ly);
					visited[lx][ly] = true;
				}
			}
			q.push(i);
			q.push(w - 1);
			visited[i][w - 1] = true;
		}
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		// printf("%d %d\n", x, y);
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			// printf("     %d %d\n", nx, ny);
			if(!(nx >= 0 && nx < h && ny >= 0 && ny < w && map[nx][ny] != '*' && !visited[nx][ny])){
				continue;
			}
			if(map[nx][ny] == '$'){
				++ret;
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}else if(map[nx][ny] >= 'A' && map[nx][ny] <= 'Z'){
				if(keys[map[nx][ny] - 'A']){
					q.push(nx);
					q.push(ny);
					visited[nx][ny] = true;
				}else{
					lockx[map[nx][ny] - 'A'].push_back(nx);
					locky[map[nx][ny] - 'A'].push_back(ny);
				}
			}else if(map[nx][ny] >= 'a' && map[nx][ny] <= 'z'){
				keys[map[nx][ny] - 'a'] = true;
				// printf("%u\n", lockx[map[nx][ny] - 'a'].size());
				for(unsigned idx = 0; idx < lockx[map[nx][ny] - 'a'].size(); ++idx){
					int lx = lockx[map[nx][ny] - 'a'][idx], ly = locky[map[nx][ny] - 'a'][idx];
					if(!visited[lx][ly]){
						q.push(lx);
						q.push(ly);
						visited[lx][ly] = true;
					}
				}
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}else{
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
	return ret;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int h, w;
		scanf("%d %d", &h, &w);
		char map[MAX][MAX];
		for(int i = 0; i < h; ++i){
			scanf("%s", map[i]);
		}
		char john[30];
		scanf("%s", john);
		vector<bool> keys(26);
		for(int k = 0; john[k] != '\0' && john[k] != '0'; ++k){
			keys[john[k] - 'a'] = true;
		}
		printf("%d\n", documents(map, keys, h, w));
	}
	return 0;
}
