#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main(){
	unsigned n;
	scanf("%u", &n);
	priority_queue<int, vector<int>, greater<int>> pq;
	for(unsigned i = 0; i < n; ++i){
		for(unsigned j = 0; j < n; ++j){
			int x;
			scanf("%d", &x);
			pq.push(x);
			if(pq.size() > n){
				pq.pop();
			}
		}
	}
	printf("%d", pq.top());
	return 0;
}
