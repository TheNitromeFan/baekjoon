#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	priority_queue<unsigned, vector<unsigned>, greater<unsigned>> pq;
	unsigned ans = 0;
	vector<pair<unsigned, unsigned>> v;
	for(int i = 0; i < n; ++i){
		unsigned d, p;
		scanf("%u %u", &p, &d);
		v.push_back(make_pair(d, p));
	}
	sort(v.begin(), v.end());
	for(auto x : v){
		unsigned d = x.first, p = x.second;
		ans += p;
		pq.push(p);
		if(pq.size() > d){
			ans -= pq.top();
			pq.pop();
		}
	}
	printf("%u", ans);
	return 0;
}
