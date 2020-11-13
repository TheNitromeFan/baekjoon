#include <cstdio>
#include <deque>

#define MAX 100000

using namespace std;

int bfs(int src, int dest){
	deque<int> queue;
	int dist[MAX+1] = {0};
	bool visited[MAX+1] = {false};
	queue.push_back(src);
	visited[src] = true;
	while(!visited[dest]){
		int curr = queue[0];
		queue.pop_front();
		if(curr+1 <= MAX && !visited[curr+1]){
			dist[curr+1] = dist[curr] + 1;
			queue.push_back(curr+1);
			visited[curr+1] = true;
		}
		if(curr-1 >= 0 && !visited[curr-1]){
			dist[curr-1] = dist[curr] + 1;
			queue.push_back(curr-1);
			visited[curr-1] = true;
		}
		if(2*curr <= MAX && !visited[2*curr]){
			dist[2*curr] = dist[curr] + 1;
			queue.push_back(2*curr);
			visited[2*curr] = true;
		}
	}
	return dist[dest];
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", bfs(n, k));
	return 0;
}
