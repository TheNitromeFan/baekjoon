#include <cstdio>
#include <queue>
#include <vector>
#include <functional>

using std::priority_queue;
using std::vector;
using std::greater;

int main(){
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(x == 0){
			if(pq.empty()){
				printf("0\n");
				continue;
			}
			printf("%d\n", pq.top());
			pq.pop();
		}else{
			pq.push(x);
		}
	}
	return 0;
}
