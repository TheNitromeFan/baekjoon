#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int m1, m2;
		scanf("%d", &m1);
		for(int j = 0; j < m1; ++j){
			int u, v;
			scanf("%d %d", &u, &v);
		}
		scanf("%d", &m2);
		for(int j = 0; j < m2; ++j){
			int u, v;
			scanf("%d %d", &u, &v);
		}
		printf("%s\n", m1 == m2 ? "yes" : "no");
	}
	return 0;
}
