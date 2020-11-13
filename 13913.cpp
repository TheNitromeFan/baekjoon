#include <cstdio>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	queue<int> q;
	map<int, int> prev;
	q.push(n);
	prev[n] = -1;
	int cnt = 0;
	stack<int> s;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(x == k){
			do{
				s.push(x);
				x = prev[x];
				++cnt;
			}while(x != -1);
			break;
		}
		if(x < k && prev.find(2 * x) == prev.end()){
			q.push(2 * x);
			prev[2 * x] = x;
		}
		if(prev.find(x + 1) == prev.end()){
			q.push(x + 1);
			prev[x + 1] = x;
		}
		if(x > 0 && prev.find(x - 1) == prev.end()){
			q.push(x - 1);
			prev[x - 1] = x;
		}
	}
	printf("%d\n", cnt - 1);
	while(!s.empty()){
		printf("%d ", s.top());
		s.pop();
	}
	return 0;
}
