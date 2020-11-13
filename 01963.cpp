#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 10000

using namespace std;

void sieve(bool primes[MAX]){
	memset(primes, true, sizeof(bool) * MAX);
	primes[0] = false;
	primes[1] = false;
	for(int p = 2; p * p < MAX; ++p){
		if(!primes[p]){
			continue;
		}
		for(int m = p; m * p < MAX; ++m){
			primes[m * p] = false;
		}
	}
}

int bfs(bool primes[MAX], int start, int end){
	queue<int> q;
	int visited[MAX] = {};
	q.push(start / 1000);
	q.push((start / 100) % 10);
	q.push((start / 10) % 10);
	q.push(start % 10);
	while(!q.empty()){
		int a = q.front();
		q.pop();
		int b = q.front();
		q.pop();
		int c = q.front();
		q.pop();
		int d = q.front();
		q.pop();
		int number = 1000 * a + 100 * b + 10 * c + d;
		if(number == end){
			return visited[number];
		}
		for(int i = 1; i <= 9; ++i){
			int n = 1000 * i + 100 * b + 10 * c + d;
			if(n != start && primes[n] && visited[n] == 0){
				visited[n] = visited[number] + 1;
				q.push(i);
				q.push(b);
				q.push(c);
				q.push(d);
			}
		}
		for(int i = 0; i <= 9; ++i){
			int n = 1000 * a + 100 * i + 10 * c + d;
			if(n != start && primes[n] && visited[n] == 0){
				visited[n] = visited[number] + 1;
				q.push(a);
				q.push(i);
				q.push(c);
				q.push(d);
			}
		}
		for(int i = 0; i <= 9; ++i){
			int n = 1000 * a + 100 * b + 10 * i + d;
			if(n != start && primes[n] && visited[n] == 0){
				visited[n] = visited[number] + 1;
				q.push(a);
				q.push(b);
				q.push(i);
				q.push(d);
			}
		}
		for(int i = 0; i <= 9; ++i){
			int n = 1000 * a + 100 * b + 10 * c + i;
			if(n != start && primes[n] && visited[n] == 0){
				visited[n] = visited[number] + 1;
				q.push(a);
				q.push(b);
				q.push(c);
				q.push(i);
			}
		}
		
	}
	return -1;
}

int main(){
	bool primes[MAX];
	sieve(primes);
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int start, goal;
		scanf("%d %d", &start, &goal);
		int ans = bfs(primes, start, goal);
		if(ans == -1){
			printf("Impossible\n");
		}else{
			printf("%d\n", ans);
		}
	}
	return 0;
}
