#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int turnaround;
		scanf("%d", &turnaround);
		int na, nb;
		scanf("%d %d", &na, &nb);
		vector<tuple<int, int, bool>> times(na + nb);
		for(int i = 0; i < na; ++i){
			int h1, m1, h2, m2;
			scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
			get<0>(times[i]) = 60 * h1 + m1;
			get<1>(times[i]) = 60 * h2 + m2;
			get<2>(times[i]) = true;
		}
		for(int i = na; i < na + nb; ++i){
			int h1, m1, h2, m2;
			scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
			get<0>(times[i]) = 60 * h1 + m1;
			get<1>(times[i]) = 60 * h2 + m2;
			get<2>(times[i]) = false;
		}
		sort(times.begin(), times.end());
		priority_queue<int, vector<int>, greater<int>> a, b;
		int ansA = 0, ansB = 0;
		for(int i = 0; i < na + nb; ++i){
			if(get<2>(times[i])){
				if(!a.empty() && a.top() <= get<0>(times[i])){
					a.pop();
				}else{
					++ansA;
				}
				b.push(get<1>(times[i]) + turnaround);
			}else{
				if(!b.empty() && b.top() <= get<0>(times[i])){
					b.pop();
				}else{
					++ansB;
				}
				a.push(get<1>(times[i]) + turnaround);
			}
		}
		printf("Case #%d: %d %d\n", a0, ansA, ansB);
	}
	return 0;
}
