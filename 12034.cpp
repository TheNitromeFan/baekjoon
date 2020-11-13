#include <cstdio>
#include <queue>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		int n;
		scanf("%d", &n);
		printf("Case #%d: ", i);
		queue<int> q;
		for(int j = 0; j < 2 * n; ++j){
			int x;
			scanf("%d", &x);
			if(!q.empty() && q.front() % 3 == 0 && q.front() / 3 * 4 == x){
				printf("%d ", q.front());
				q.pop();
			}else{
				q.push(x);
			}
		}
		printf("\n");
	}
	return 0;
}
