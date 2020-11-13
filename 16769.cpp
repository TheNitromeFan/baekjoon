#include <cstdio>
#include <algorithm>

int main(){
	int c[3], m[3];
	for(int i = 0; i < 3; ++i){
		scanf("%d %d", &c[i], &m[i]);
	}
	for(int pour = 0; pour < 100; ++pour){
		int src = pour % 3, dest = (pour + 1) % 3;
		int amt = std::min(m[src], c[dest] - m[dest]);
		m[src] -= amt;
		m[dest] += amt;
	}
	for(int i = 0; i < 3; ++i){
		printf("%d\n", m[i]);
	}
	return 0;
}
