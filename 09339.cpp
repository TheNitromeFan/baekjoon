#include <cstdio>
#include <set>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int k;
		scanf("%d", &k);
		std::set<int> part;
		for(int i = 0; i < k; ++i){
			int x;
			scanf("%d", &x);
			part.insert(x);
		}
		int n;
		scanf("%d", &n);
		int best = 0, ans = 0, time = 6 * 60 + 1;
		for(int j = 0; j < n; ++j){
			int x, h, m;
			scanf("%d %d %d", &x, &h, &m);
			if(part.find(x) != part.end() && !(h == -1 && m == -1) && h * 60 + m <= 6 * 60){
				++ans;
				if(h * 60 + m < time){
					best = x;
					time = h * 60 + m;
				}
			}
		}
		printf("%d %d\n", best, ans);
	}
	return 0;
}
