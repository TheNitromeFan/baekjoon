#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	vector<pair<int, int>> jewelry;
	jewelry.resize(n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &jewelry[i].first, &jewelry[i].second);
	}
	vector<int> bags(k, 0);
	for(int j = 0; j < k; ++j){
		scanf("%d", &bags[j]);
	}
	sort(jewelry.begin(), jewelry.end());
	sort(bags.begin(), bags.end());
	priority_queue<int> pq;
	long long ans = 0;
	int idx = 0;
	for(int j = 0; j < k; ++j){
		while(idx < n && jewelry[idx].first <= bags[j]){
			pq.push(jewelry[idx].second);
			++idx;
		}
		if(!pq.empty()){
			ans += pq.top();
			pq.pop();
		}
	}
	printf("%lld", ans);
	return 0;
}
