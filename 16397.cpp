#include <cstdio>
#include <queue>
#define MAX 99999

using namespace std;

int transform(int number){
	int n = 2 * number;
	int ten_power = 1;
	while(ten_power * 10 <= n){
		ten_power *= 10;
	}
	return n - ten_power;
}

int bfs(int start, int time, int goal){
	int visited[MAX + 1] = {};
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(visited[x] > time){
			return -1;
		}else if(x == goal){
			return visited[x];
		}
		int a = x + 1;
		if(a <= MAX && a != start && visited[a] == 0){
			visited[a] = visited[x] + 1;
			q.push(a);
		}
		if(x == 0 || 2 * x > MAX){
			continue;
		}
		int b = transform(x);
		if(b != start && visited[b] == 0){
			visited[b] = visited[x] + 1;
			q.push(b);
		}
	}
	return -1;
}

int main(){
	int n, t, g;
	scanf("%d %d %d", &n, &t, &g);
	int ans = bfs(n, t, g);
	if(ans == -1){
		printf("ANG");
	}else{
		printf("%d", ans);
	}
	return 0;
}
