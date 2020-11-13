#include <cstdio>
#include <deque>
#include <algorithm>

using std::deque;
using std::sort;

deque<int> components(int graph[][25], int d){
	int dx[8] = {-1, 0, 1, 0};
	int dy[8] = {0, 1, 0, -1};
	bool visited[25][25];
	for(int i = 0; i < d; ++i){
		for(int j = 0; j < d; ++j){
			visited[i][j] = false;
		}
	}
	deque<int> queue;
	deque<int> deck;
	int component_count = 0;
	for(int i = 0; i < d; ++i){
		for(int j = 0; j < d; ++j){
			if(graph[i][j] == 1 && !visited[i][j]){
				queue.push_back(i);
				queue.push_back(j);
				visited[i][j] = true;
				int houses = 1;
				++component_count;
				while(!queue.empty()){
					int x = queue[0];
					queue.pop_front();
					int y = queue[0];
					queue.pop_front();
					for(int ind = 0; ind < 4; ++ind){
						if(x+dx[ind] >= 0 && x+dx[ind] < d && y+dy[ind] >= 0 && y+dy[ind] < d
						&& graph[x+dx[ind]][y+dy[ind]] == 1 && !visited[x+dx[ind]][y+dy[ind]]){
							queue.push_back(x+dx[ind]);
							queue.push_back(y+dy[ind]);
							visited[x+dx[ind]][y+dy[ind]] = true;
							++houses;
						}
					}
				}
				deck.push_back(houses);
			}
		}
	}
	deck.push_front(component_count);
	return deck;
}

int main(){
	int x;
	scanf("%d", &x);
	int c[25][25];
	char input[26];
	for(int i = 0; i < x; ++i){
		scanf("%s", input);
		for(int j = 0; j < x; ++j){
			c[i][j] = input[j] - '0';
		}
	}
	deque<int> answer_deque = components(c, x);
	int len = answer_deque[0];
	answer_deque.pop_front();
	printf("%d", len);
	sort(answer_deque.begin(), answer_deque.end());
	for(int i = 0; i < len; ++i){
		printf("\n%d", answer_deque[i]);
	}
	return 0;
}
