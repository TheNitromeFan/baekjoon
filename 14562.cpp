#include <cstdio>
#include <queue>

using std::queue;

int kicks(int s, int t){
	queue<int> q;
	q.push(s);
	q.push(t);
	q.push(0);
	while(!q.empty()){
		int a = q.front();
		q.pop();
		int b = q.front();
		q.pop();
		int x = q.front();
		q.pop();
		if(a == b){
			return x;
		}
		q.push(a + 1);
		q.push(b);
		q.push(x + 1);
		int na = 2 * a, nb = b + 3;
		if(na <= nb){
			q.push(na);
			q.push(nb);
			q.push(x + 1);
		}
	}
	return -1;
}

int main(){
	int c;
	scanf("%d", &c);
	for(int i = 0; i < c; ++i){
		int s, t;
		scanf("%d %d", &s, &t);
		printf("%d\n", kicks(s, t));
	}
	return 0;
}
