#include <cstdio>
#include <deque>
#include <algorithm>

using std::deque;
using std::sort;

deque<int> components(int graph[][100], int n, int m){
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	bool visited[100][100];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			visited[i][j] = false;
		}
	}
	deque<int> queue;
	deque<int> deck;
	int component_count = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(graph[i][j] == 0 && !visited[i][j]){
				queue.push_back(i);
				queue.push_back(j);
				visited[i][j] = true;
				int area = 1;
				++component_count;
				while(!queue.empty()){
					int x = queue[0];
					queue.pop_front();
					int y = queue[0];
					queue.pop_front();
					for(int ind = 0; ind < 4; ++ind){
						if(x+dx[ind] >= 0 && x+dx[ind] < n && y+dy[ind] >= 0 && y+dy[ind] < m
						&& graph[x+dx[ind]][y+dy[ind]] == 0 && !visited[x+dx[ind]][y+dy[ind]]){
							queue.push_back(x+dx[ind]);
							queue.push_back(y+dy[ind]);
							visited[x+dx[ind]][y+dy[ind]] = true;
							++area;
						}
					}
				}
				deck.push_back(area);
			}
		}
	}
	deck.push_front(component_count);
	return deck;
}

int main(){
	int m, n, k;
	scanf("%d %d %d", &m, &n, &k);
	int paper[100][100];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			paper[i][j] = 0;
		}
	}
	for(int a0 = 0; a0 < k; ++a0){
		int x0, y0, x1, y1;
		scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
		for(int x = x0; x < x1; ++x){
			for(int y = y0; y < y1; ++y){
				paper[x][y] = 1;
			}
		}
	}
	/*
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			printf("%d ", paper[i][j]);
		}
		printf("\n");
	}
	*/
	deque<int> answer_deque = components(paper, n, m);
	int len = answer_deque[0];
	answer_deque.pop_front();
	printf("%d\n", len);
	sort(answer_deque.begin(), answer_deque.end());
	for(int i = 0; i < len; ++i){
		printf("%d ", answer_deque[i]);
	}
	return 0;
}
