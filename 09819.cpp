#include <cstdio>
#include <vector>

using std::vector;

int main(){
	int n, m, k;
	while(scanf("%d,%d,%d", &n, &m, &k) == 3){
		vector<bool> ring(m, true);
		ring.resize(n);
		for(int a0 = 0; a0 < k; ++a0){
			vector<bool> ring1(n);
			for(int i = 0; i < n; ++i){
				ring1[i] = ring[i] ^ ring[(i + 1) % n];
			}
			ring = ring1;
		}
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			if(ring[i]){
				++cnt;
			}
		}
		printf("%d,%d,%d: %d\n", n, m, k, cnt);
	}
	return 0;
}
