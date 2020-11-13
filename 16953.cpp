#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int bfs(long long start, long long end){
	queue<pair<long long, int>> q;
	q.push(make_pair(start, 1));
	while(!q.empty()){
		auto p = q.front();
		q.pop();
		long long x = p.first;
		int cnt = p.second;
		if(x == end){
			return cnt;
		}
		if(x * 2 <= end){
			q.push(make_pair(x * 2, cnt + 1));
		}
		if(x * 10 + 1 <= end){
			q.push(make_pair(x * 10 + 1, cnt + 1));
		}
	}
	return -1;
}

int main(){
	long long a, b;
	scanf("%lld %lld", &a, &b);
	printf("%d", bfs(a, b));
	return 0;
}
