#include <cstdio>
#include <algorithm>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		scanf("%d %d", &n, &m);
		int q[150];
		for(int a1 = 0; a1 < n; ++a1){
			scanf("%d", &q[a1]);
		}
		int time = 0;
		for(int p = 0; q[m] > 0; p = (p+1) % n){
			if(q[p] > 0){
				int mx = 0;
				for(int i = 0; i < n; ++i){
					mx = std::max(mx, q[i]);
				}
				if(q[p] >= mx){
					++time;
					q[p] = 0;
				}
			}
		}
		printf("%d\n", time);
	}
	return 0;
}
