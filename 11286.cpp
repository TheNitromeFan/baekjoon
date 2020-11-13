#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

auto cmp = [](int a, int b){
	return (abs(a) > abs(b)) || (abs(a) == abs(b) && a > b);
};

int main(){
	priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
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
