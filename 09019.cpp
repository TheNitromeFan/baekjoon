#include <cstdio>
#include <string>
#include <queue>
#define MAX 10000

using namespace std;

string bfs(int start, int end){
	queue<int> q;
	string visited[MAX] = {};
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
		int n;
		n = 2 * number % MAX;
		if(n != start && visited[n] == ""){
			visited[n] = visited[number] + 'D';
			q.push(n / 1000);
			q.push((n / 100) % 10);
			q.push((n / 10) % 10);
			q.push(n % 10);
		}
		n = (number + MAX - 1) % MAX;
		if(n != start && visited[n] == ""){
			visited[n] = visited[number] + 'S';
			q.push(n / 1000);
			q.push((n / 100) % 10);
			q.push((n / 10) % 10);
			q.push(n % 10);
		}
		n = 1000 * b + 100 * c + 10 * d + a;
		if(n != start && visited[n] == ""){
			visited[n] = visited[number] + 'L';
			q.push(b);
			q.push(c);
			q.push(d);
			q.push(a);
		}
		n = 1000 * d + 100 * a + 10 * b + c;
		if(n != start && visited[n] == ""){
			visited[n] = visited[number] + 'R';
			q.push(d);
			q.push(a);
			q.push(b);
			q.push(c);
		}
	}
	return "IMPOSSIBLE";
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%s\n", bfs(a, b).c_str());
	}
	return 0;
}
