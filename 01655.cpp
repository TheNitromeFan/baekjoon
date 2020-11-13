#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	priority_queue<int, vector<int>, less<int>> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(max_heap.empty() || max_heap.size() == min_heap.size()){
			max_heap.push(x);
		}else{
			min_heap.push(x);
		}
		if(!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()){
			int a = max_heap.top();
			max_heap.pop();
			int b = min_heap.top();
			min_heap.pop();
			max_heap.push(b);
			min_heap.push(a);
		}
		printf("%d\n", max_heap.top());
	}
	return 0;
}
