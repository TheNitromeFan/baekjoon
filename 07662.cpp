#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

int main(){
	int t;
	scanf("%d\n", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int k;
		scanf("%d\n", &k);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
		priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> maxHeap;
		vector<bool> visited(k, false);
		for(int i = 0; i < k; ++i){
			char op;
			int num;
			scanf("%c %d\n", &op, &num);
			if(op == 'D'){
				if(num == 1){
					while(!maxHeap.empty() && !visited[maxHeap.top().second]){
						maxHeap.pop();
					}
					if(!maxHeap.empty()){
						visited[maxHeap.top().second] = false;
						maxHeap.pop();
					}
				}else{
					while(!minHeap.empty() && !visited[minHeap.top().second]){
						minHeap.pop();
					}
					if(!minHeap.empty()){
						visited[minHeap.top().second] = false;
						minHeap.pop();
					}
				}
			}else{
				minHeap.push(make_pair(num, i));
				maxHeap.push(make_pair(num, i));
				visited[i] = true;
			}
		}
		while(!minHeap.empty() && !visited[minHeap.top().second]){
			minHeap.pop();
		}
		while(!maxHeap.empty() && !visited[maxHeap.top().second]){
			maxHeap.pop();
		}
		if(minHeap.empty() && maxHeap.empty()){
			printf("EMPTY\n");
		}else{
			printf("%d %d\n", maxHeap.top().first, minHeap.top().first);
		}
	}
	return 0;
}
