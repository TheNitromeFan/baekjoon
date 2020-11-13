#include <cstdio>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	map<int, bool> sold;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(sold.find(x) == sold.end()){
			sold[x] = true;
			pq.push(x);
		}
	}
	int ans = 1;
	while(!pq.empty()){
		int x = pq.top();
		pq.pop();
		if(ans < x){
			break;
		}
		++ans;
	}
	printf("%d", ans);
	return 0;
}
