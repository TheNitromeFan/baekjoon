#include <cstdio>
#include <deque>

using std::deque;

int components(int graph[][50], int w, int h){
	int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	bool visited[50][50];
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			visited[i][j] = false;
		}
	}
	deque<int> queue;
	int answer = 0;
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			if(graph[i][j] == 1 && !visited[i][j]){
				queue.push_back(i);
				queue.push_back(j);
				visited[i][j] = true;
				++answer;
				while(!queue.empty()){
					int x = queue[0];
					queue.pop_front();
					int y = queue[0];
					queue.pop_front();
					for(int ind = 0; ind < 8; ++ind){
						if(x+dx[ind] >= 0 && x+dx[ind] < h && y+dy[ind] >= 0 && y+dy[ind] < w
						&& graph[x+dx[ind]][y+dy[ind]] == 1 && !visited[x+dx[ind]][y+dy[ind]]){
							queue.push_back(x+dx[ind]);
							queue.push_back(y+dy[ind]);
							visited[x+dx[ind]][y+dy[ind]] = true;
						}
					}
				}
			}
		}
	}
	return answer;
}

int main(){
	while(true){
		int w, h;
		scanf("%d %d", &w, &h);
		if(w == 0 && h == 0){
			break;
		}
		int c[50][50];
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				scanf("%d", &c[i][j]);
			}
		}
		printf("%d\n", components(c, w, h));
	}
	return 0;
}
