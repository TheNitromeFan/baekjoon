#include <cstdio>
#include <queue>

using std::queue;

int rolls(int dest[101]){
	int steps[101] = {};
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(x == 100){
			return steps[100];
		}
		for(int j = 1; j <= 6; ++j){
			int nx = x + j;
			if(nx <= 100 && steps[dest[nx]] == 0){
				q.push(dest[nx]);
				steps[dest[nx]] = steps[x] + 1;
			}
		}
	}
	return -1;
}

int main(){
	int dest[101];
	for(int i = 1; i <= 100; ++i){
		dest[i] = i;
	}
	int n, m;
	scanf("%d %d", &n, &m);
	for(int j = 0; j < n + m; ++j){
		int x, y;
		scanf("%d %d", &x, &y);
		dest[x] = y;
	}
	printf("%d", rolls(dest));
	return 0;
}
