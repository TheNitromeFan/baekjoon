#include <cstdio>
#include <deque>

using std::deque;

int components(int graph[][100], int d, int h){
	int dx[8] = {-1, 0, 1, 0};
	int dy[8] = {0, 1, 0, -1};
	bool visited[100][100];
	for(int i = 0; i < d; ++i){
		for(int j = 0; j < d; ++j){
			visited[i][j] = false;
		}
	}
	deque<int> queue;
	int answer = 0;
	for(int i = 0; i < d; ++i){
		for(int j = 0; j < d; ++j){
			if(graph[i][j] >= h && !visited[i][j]){
				queue.push_back(i);
				queue.push_back(j);
				visited[i][j] = true;
				++answer;
				while(!queue.empty()){
					int x = queue[0];
					queue.pop_front();
					int y = queue[0];
					queue.pop_front();
					for(int ind = 0; ind < 4; ++ind){
						if(x+dx[ind] >= 0 && x+dx[ind] < d && y+dy[ind] >= 0 && y+dy[ind] < d
						&& graph[x+dx[ind]][y+dy[ind]] >= h && !visited[x+dx[ind]][y+dy[ind]]){
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
	int x;
	scanf("%d", &x);
	int land[100][100];
	int highest = 0;
	for(int i = 0; i < x; ++i){
		for(int j = 0; j < x; ++j){
			scanf("%d", &land[i][j]);
			if(land[i][j] > highest){
				highest = land[i][j];
			}
		}
	}
	int max_islands = 1;
	for(int h = 1; h <= highest; ++h){
		int a = components(land, x, h);
		if(a > max_islands){
			max_islands = a;
		}
	}
	printf("%d", max_islands);
	return 0;
}
