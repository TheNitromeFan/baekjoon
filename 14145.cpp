#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define MAX 51

using namespace std;

int field_size(char map[][MAX], bool visited[][MAX], int h, int w, int sx, int sy){
	queue<int> q;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	q.push(sx);
	q.push(sy);
	visited[sx][sy] = true;
	int ret = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		++ret;
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < h && ny >= 0 && ny < w && map[nx][ny] == '1' && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
	return ret;
}

void harvest(char map[][MAX], char final[][MAX], int h, int w, int sx, int sy, char c){
	queue<int> q;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	q.push(sx);
	q.push(sy);
	final[sx][sy] = c;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < h && ny >= 0 && ny < w && map[nx][ny] == '1' && final[nx][ny] == '0'){
				q.push(nx);
				q.push(ny);
				final[nx][ny] = c;
			}
		}
	}
}

int main(){
	int h, w;
	scanf("%d %d", &h, &w);
	char wheat[MAX][MAX];
	for(int i = 0; i < h; ++i){
		scanf("%s", wheat[i]);
	}
	bool visited[MAX][MAX] = {};
	vector<pair<int, pair<int, int>>> v;
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			if(wheat[i][j] == '1' && !visited[i][j]){
				int land = field_size(wheat, visited, h, w, i, j);
				v.push_back(make_pair(land, make_pair(i, j)));
			}
		}
	}
	sort(v.begin(), v.end());
	char final[MAX][MAX];
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			final[i][j] = '0';
		}
	}
	for(int idx = 0; idx < (int)v.size(); ++idx){
		pair<int, int> p = v[idx].second;
		int x = p.first, y = p.second;
		harvest(wheat, final, h, w, x, y, '1' + idx);
	}
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			printf("%c", final[i][j]);
		}
		printf("\n");
	}
	return 0;
}
