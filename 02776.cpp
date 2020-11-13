#include <cstdio>
#include <unordered_map>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n, m;
		std::unordered_map<int, int> ma;
		scanf("%d", &n);
		for(int j = 0; j < n; ++j){
			int x;
			scanf("%d", &x);
			ma[x] = 1;
		}
		scanf("%d", &m);
		for(int k = 0; k < m; ++k){
			int x;
			scanf("%d", &x);
			printf("%d\n", ma.find(x) != ma.end());
		}
	}
	return 0;
}
